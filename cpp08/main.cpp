/* ============================================================================
 * C++ MODULE 08 - KAPSAMLI KAVRAM ÖĞRENME DOSYASI
 * ============================================================================
 * 
 * Bu dosyada öğreneceğin ana kavramlar:
 * 
 * 1. CONTAINERS (Konteynerler)
 *    - vector, list, deque, stack, map, set gibi STL konteynerlerini anlama
 *    - Her konteynerin kullanım senaryoları ve performans özellikleri
 * 
 * 2. ITERATORS (Yineleyiciler)
 *    - Iterator kavramı ve çeşitleri (begin, end, rbegin, rend)
 *    - Iterator'ları kullanarak konteynerlerde gezinme
 *    - Iterator kategorileri (input, output, forward, bidirectional, random access)
 * 
 * 3. ALGORITHMS (Algoritmalar)
 *    - <algorithm> header'ındaki hazır algoritmaları kullanma
 *    - find, sort, copy, transform gibi yaygın algoritmaları anlama
 * 
 * 4. FUNCTION TEMPLATES (Fonksiyon Şablonları)
 *    - Generic programlama ile tip-bağımsız fonksiyonlar yazma
 *    - Template parameter deduction (şablon parametre çıkarımı)
 * 
 * 5. RANGE-BASED OPERATIONS
 *    - Iterator aralıkları ile çalışma
 *    - Range constructor'lar ve range insertion
 * 
 * ============================================================================ */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <exception>
#include <limits>

// ANSI renk kodları - çıktıları daha okunabilir yapmak için
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

/* ============================================================================
 * BÖLÜM 1: FUNCTION TEMPLATES (Fonksiyon Şablonları)
 * ============================================================================
 * 
 * Template'ler C++'ın en güçlü özelliklerinden biridir. Generic programlama
 * yapmanı sağlar - yani aynı kodu farklı tipler için kullanabilirsin.
 * 
 * Template fonksiyon yazarken, compiler her kullanım için otomatik olarak
 * o tip için özel bir versiyon oluşturur. Bu işleme "template instantiation" denir.
 */

// ÖRNEK 1: Basit bir template fonksiyon - herhangi bir konteynerde arama yapar
template <typename T>
int easyfind(const T& container, int value)
{
    /* 
     * std::find algoritması:
     * - <algorithm> header'ından gelir
     * - Bir aralıkta (begin'den end'e kadar) belirli bir değeri arar
     * - İlk eşleşmeyi bulduğunda o konuma işaret eden iterator döner
     * - Bulamazsa end() iterator'ünü döner
     * 
     * Sözdizimi: std::find(başlangıç_iterator, bitiş_iterator, aranacak_değer)
     */
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    
    /*
     * Iterator karşılaştırması:
     * - it != container.end() kontrolü, değerin bulunup bulunmadığını anlamak için
     * - Eğer bulunsaydı, it end()'den farklı bir konumu gösterirdi
     */
    if (it != container.end())
    {
        /*
         * std::distance algoritması:
         * - İki iterator arasındaki mesafeyi (kaç eleman olduğunu) hesaplar
         * - Burada başlangıçtan bulunan elemana kadar kaç adım olduğunu buluyoruz
         * - Bu bize elemanın index'ini verir
         */
        return std::distance(container.begin(), it);
    }
    
    // Bulunamadıysa -1 döndür (alternatif olarak exception da fırlatabilirdik)
    return -1;
}

/* ============================================================================
 * ÖRNEK 2: Daha gelişmiş bir template - range'deki min ve max değeri bulur
 * 
 * Bu fonksiyon iki şeyi gösteriyor:
 * 1. Pair döndürme (std::pair kullanımı)
 * 2. std::min_element ve std::max_element algoritmaları
 */
template <typename T>
std::pair<int, int> findMinMax(const T& container)
{
    // Container boşsa exception fırlat
    if (container.empty())
        throw std::runtime_error("Container is empty!");
    
    /*
     * std::min_element ve std::max_element:
     * - Container'daki en küçük/büyük elemanı bulur
     * - Bu elemanların konumunu gösteren iterator döner
     * - Dereference (*) ile o konumdaki değere erişiriz
     */
    typename T::const_iterator minIt = std::min_element(container.begin(), container.end());
    typename T::const_iterator maxIt = std::max_element(container.begin(), container.end());
    
    /*
     * std::pair kullanımı:
     * - İki değeri birlikte tutmak için kullanılan basit bir yapı
     * - std::make_pair ile kolay oluşturulur
     * - .first ve .second ile elemanlara erişilir
     */
    return std::make_pair(*minIt, *maxIt);
}

/* ============================================================================
 * BÖLÜM 2: SPAN - Range İşlemleri ve Distance Kavramı
 * ============================================================================
 * 
 * Bu class Span exercise'ını basitleştirilmiş halde gösterir.
 * Öğreteceği kavramlar:
 * - Range constructor (iterator aralığı ile construction)
 * - Distance calculation (elemanlar arası mesafe hesaplama)
 * - Exception handling
 * - std::sort kullanımı
 */

class SimpleSpan
{
private:
    /*
     * std::vector seçimi:
     * - Dinamik boyutlu array gibi çalışır
     * - Random access (direkt index ile erişim) O(1)
     * - push_back ile sona ekleme genelde O(1)
     * - Sort edilebilir (random access iterator'a sahip olduğu için)
     */
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:
    // Constructor - maksimum kapasite belirlenir
    explicit SimpleSpan(unsigned int N) : _maxSize(N) 
    {
        // Performans için memory'yi önceden reserve edebiliriz
        _numbers.reserve(N);
    }
    
    // Tek eleman ekleme
    void addNumber(int number)
    {
        if (_numbers.size() >= _maxSize)
            throw std::runtime_error("Span is full!");
        _numbers.push_back(number);
    }
    
    /*
     * RANGE EKLEME - ÇOK ÖNEMLİ KAVRAM!
     * 
     * Template fonksiyon - herhangi bir iterator tipi ile çalışabilir
     * Bu sayede vector'den, list'ten, array'den vb. kopyalama yapabiliriz
     * 
     * InputIterator: Iterator kategorisi (input iterator veya daha iyisi)
     */
    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last)
    {
        /*
         * std::distance ile aralıktaki eleman sayısını hesapla
         * Eğer kapasite aşılacaksa exception fırlat
         */
        size_t count = std::distance(first, last);
        if (_numbers.size() + count > _maxSize)
            throw std::runtime_error("Cannot add range: would exceed capacity!");
        
        /*
         * Iterator aralığını kullanarak toplu ekleme
         * Bu, STL'in en güçlü özelliklerinden biri!
         * 
         * vector::insert() fonksiyonu:
         * - İlk parametre: nereye ekleyeceğimiz (end = sona ekle)
         * - İkinci ve üçüncü: kaynak aralığın başı ve sonu
         */
        _numbers.insert(_numbers.end(), first, last);
    }
    
    // En kısa mesafeyi bul
    unsigned int shortestSpan() const
    {
        if (_numbers.size() < 2)
            throw std::runtime_error("Need at least 2 numbers!");
        
        /*
         * Strateji:
         * 1. Vector'ü sırala (küçükten büyüğe)
         * 2. Ardışık elemanlar arasındaki farkları hesapla
         * 3. En küçüğünü bul
         * 
         * Not: Sıralı dizide en küçük fark mutlaka komşu elemanlar arasındadır!
         */
        std::vector<int> sorted = _numbers; // Kopyasını al (const olduğu için)
        std::sort(sorted.begin(), sorted.end());
        
        unsigned int minSpan = std::numeric_limits<unsigned int>::max();
        
        /*
         * Iterator'larla gezinme örneği:
         * - begin() + 1'den başla (çünkü bir öncekiyle karşılaştıracağız)
         * - end()'e kadar git
         * - Her iterasyonda *it (şimdiki) ve *(it-1) (önceki) farkını al
         */
        for (std::vector<int>::const_iterator it = sorted.begin() + 1; 
             it != sorted.end(); ++it)
        {
            unsigned int span = *it - *(it - 1);
            if (span < minSpan)
                minSpan = span;
        }
        
        return minSpan;
    }
    
    // En uzun mesafeyi bul
    unsigned int longestSpan() const
    {
        if (_numbers.size() < 2)
            throw std::runtime_error("Need at least 2 numbers!");
        
        /*
         * En uzun mesafe = max - min
         * Basit ama etkili!
         */
        std::pair<int, int> minmax = findMinMax(_numbers);
        return minmax.second - minmax.first;
    }
    
    // Yazdırma fonksiyonu - debug için kullanışlı
    void print() const
    {
        std::cout << "[ ";
        for (std::vector<int>::const_iterator it = _numbers.begin(); 
             it != _numbers.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << "]" << std::endl;
    }
};

/* ============================================================================
 * BÖLÜM 3: MUTANT STACK - Container Adaptor ve Iterator Ekleme
 * ============================================================================
 * 
 * std::stack normalde iterable değildir (begin/end yok).
 * Biz onu "miras alarak" ve underlying container'ı expose ederek
 * iterable yapacağız.
 * 
 * Öğreteceği kavramlar:
 * - Container adaptor nedir
 * - Protected inheritance kullanımı
 * - Iterator typedef'leri
 * - Underlying container'a erişim
 */

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    /*
     * ITERATOR TYPEDEF'LERİ
     * 
     * std::stack içeride std::deque kullanır (default olarak).
     * std::stack::c -> protected member, underlying container'dır.
     * 
     * Biz bu container'ın iterator'lerini expose ediyoruz.
     * Böylece MutantStack iterable hale geliyor!
     */
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    /*
     * ITERATOR ACCESS FUNCTIONS
     * 
     * Bu fonksiyonlar sayesinde range-based iteration yapabiliriz:
     * for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
     */
    
    // Normal forward iterators (baştan sona)
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    
    // Reverse iterators (sondan başa)
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

/* ============================================================================
 * BÖLÜM 4: FARKLI CONTAINER TİPLERİNİN KARŞILAŞTIRMASI
 * ============================================================================
 * 
 * STL'de farklı container'lar farklı use case'ler için optimize edilmiştir.
 * Her birinin avantaj ve dezavantajlarını görelim.
 */

void demonstrateContainers()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "CONTAINER TİPLERİ VE ÖZELLİKLERİ\n";
    std::cout << "========================================\n" << RESET;
    
    /* ------------------------------------------------------------------------
     * 1. VECTOR - Dinamik Array
     * ------------------------------------------------------------------------
     * Özellikleri:
     * - Random access: O(1)
     * - Push back: Amortized O(1)
     * - Insert/Delete ortadan: O(n)
     * - Memory: Contiguous (ardışık bellek)
     * 
     * Ne zaman kullanılır:
     * - Index ile erişim gerektiğinde
     * - Sona ekleme/çıkarma işlemleri ağırlıklıysa
     * - Cache-friendly performance istendiğinde
     */
    std::cout << YELLOW << "\n1. VECTOR Örneği:\n" << RESET;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    std::cout << "Vector elemanları: ";
    // Range-based for loop (C++11) alternatifi olarak iterator kullanımı:
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nRandom access: vec[1] = " << vec[1] << std::endl;
    
    /* ------------------------------------------------------------------------
     * 2. LIST - Doubly Linked List
     * ------------------------------------------------------------------------
     * Özellikleri:
     * - Random access: YOK (index ile erişim yok)
     * - Insert/Delete herhangi bir yerden: O(1) - eğer pozisyon biliniyorsa
     * - Sequential access: O(n)
     * - Memory: Non-contiguous (dağınık bellek)
     * 
     * Ne zaman kullanılır:
     * - Çok sık insert/delete yapılacaksa
     * - Sequential access yeterliyse
     * - Elemanların memory'de yanyana olması gerekmiyorsa
     */
    std::cout << YELLOW << "\n2. LIST Örneği:\n" << RESET;
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_front(50); // List'in avantajı: başa da O(1)'de ekleyebiliriz!
    
    std::cout << "List elemanları: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // List'te ortaya eleman ekleme çok verimli:
    std::list<int>::iterator it = lst.begin();
    ++it; // İkinci elemana git
    lst.insert(it, 75); // İkinci elemanın önüne 75 ekle
    
    std::cout << "75 eklendikten sonra: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * 3. DEQUE - Double Ended Queue
     * ------------------------------------------------------------------------
     * Özellikleri:
     * - Random access: O(1)
     * - Push/Pop both ends: O(1)
     * - Insert/Delete ortadan: O(n)
     * - Memory: Chunk-based (parça parça ama neredeyse contiguous gibi)
     * 
     * Ne zaman kullanılır:
     * - Hem baştan hem sondan ekleme/çıkarma gerektiğinde
     * - Random access de istendiğinde
     * - Vector gibi ama reallocation olmasın istendiğinde
     */
    std::cout << YELLOW << "\n3. DEQUE Örneği:\n" << RESET;
    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_front(5);   // Başa ekleme O(1)!
    deq.push_front(1);
    
    std::cout << "Deque elemanları: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nRandom access: deq[2] = " << deq[2] << std::endl;
    
    /* ------------------------------------------------------------------------
     * 4. STACK - Container Adaptor (LIFO)
     * ------------------------------------------------------------------------
     * Özellikleri:
     * - Sadece top'a erişim
     * - Push/Pop: O(1)
     * - No iteration (normalde)
     * - Underlying container: deque (default), vector veya list olabilir
     * 
     * Ne zaman kullanılır:
     * - LIFO (Last In First Out) davranış gerektiğinde
     * - Sadece en üstteki elemanla ilgilenildiğinde
     * - Örnek: undo/redo mekanizmaları, function call stack simülasyonu
     */
    std::cout << YELLOW << "\n4. STACK Örneği:\n" << RESET;
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    
    std::cout << "Stack top: " << stk.top() << std::endl;
    stk.pop();
    std::cout << "Pop sonrası top: " << stk.top() << std::endl;
    std::cout << "Stack size: " << stk.size() << std::endl;
    
    /* ------------------------------------------------------------------------
     * 5. MAP - Associative Container (Key-Value Pairs)
     * ------------------------------------------------------------------------
     * Özellikleri:
     * - Unique keys (her key bir kere)
     * - Sorted by key (red-black tree implementation)
     * - Access by key: O(log n)
     * - Insert/Delete: O(log n)
     * 
     * Ne zaman kullanılır:
     * - Key-value eşleştirmesi gerektiğinde
     * - Sorted order önemliyse
     * - Fast lookup by key gerektiğinde
     */
    std::cout << YELLOW << "\n5. MAP Örneği:\n" << RESET;
    std::map<std::string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 22;
    
    std::cout << "Map elemanları (alfabetik sırayla):\n";
    /*
     * Map iterator'ı std::pair<const Key, Value> döner
     * .first = key, .second = value
     */
    for (std::map<std::string, int>::iterator it = ages.begin(); 
         it != ages.end(); ++it)
    {
        std::cout << "  " << it->first << ": " << it->second << " years old\n";
    }
    
    // Map'te arama yapmak:
    std::map<std::string, int>::iterator found = ages.find("Bob");
    if (found != ages.end())
        std::cout << "Bob bulundu, yaşı: " << found->second << std::endl;
    
    /* ------------------------------------------------------------------------
     * 6. SET - Unique Elements (Sorted)
     * ------------------------------------------------------------------------
     * Özellikleri:
     * - Unique elements (tekrarsız)
     * - Sorted (küçükten büyüğe)
     * - Insert/Delete/Find: O(log n)
     * - No random access
     * 
     * Ne zaman kullanılır:
     * - Unique elemanlar saklanacaksa
     * - Membership testing (eleman var mı kontrolü) gerektiğinde
     * - Sorted order istendiğinde
     */
    std::cout << YELLOW << "\n6. SET Örneği:\n" << RESET;
    std::set<int> numSet;
    numSet.insert(5);
    numSet.insert(2);
    numSet.insert(8);
    numSet.insert(2); // Duplicate, eklenmeyecek!
    numSet.insert(1);
    
    std::cout << "Set elemanları (otomatik sıralı): ";
    for (std::set<int>::iterator it = numSet.begin(); it != numSet.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nSet size: " << numSet.size() << " (2 sadece bir kere eklendi)" << std::endl;
    
    // Set'te eleman var mı kontrolü:
    if (numSet.find(8) != numSet.end())
        std::cout << "8 set'te var!" << std::endl;
}

/* ============================================================================
 * BÖLÜM 5: ALGORITHM HEADER'DAN YAYGIN ALGORITMALAR
 * ============================================================================
 * 
 * <algorithm> header'ı 100'den fazla hazır algoritma içerir.
 * En yaygın kullanılanları görelim.
 */

void demonstrateAlgorithms()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "STL ALGORİTMALARI\n";
    std::cout << "========================================\n" << RESET;
    
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(1);
    numbers.push_back(9);
    numbers.push_back(3);
    
    std::cout << YELLOW << "\nOrijinal vector: " << RESET;
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::sort - Sıralama
     * Complexity: O(n log n)
     * Random access iterator gerektirir (vector, deque çalışır; list çalışmaz)
     */
    std::cout << YELLOW << "\n1. std::sort kullanımı:\n" << RESET;
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted: ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::reverse - Ters çevirme
     * Complexity: O(n)
     */
    std::cout << YELLOW << "\n2. std::reverse kullanımı:\n" << RESET;
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed: ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::count - Belirli bir değerin kaç kere geçtiğini sayar
     * Complexity: O(n)
     */
    std::cout << YELLOW << "\n3. std::count kullanımı:\n" << RESET;
    numbers.push_back(5);
    numbers.push_back(5);
    int count = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "5 sayısı " << count << " kere geçiyor" << std::endl;
    
    /* ------------------------------------------------------------------------
     * Elemanların toplamını manuel hesaplama
     * Complexity: O(n)
     * Not: std::accumulate <numeric> header'ında ama biz manual yapıyoruz
     */
    std::cout << YELLOW << "\n4. Elemanların toplamı:\n" << RESET;
    int sum = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        sum += *it;
    std::cout << "Toplam: " << sum << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::find_if - Koşula uyan ilk elemanı bulur
     * Complexity: O(n)
     */
    std::cout << YELLOW << "\n5. std::find_if kullanımı:\n" << RESET;
    // 5'ten büyük ilk sayıyı bul
    std::vector<int>::iterator it = std::find_if(numbers.begin(), numbers.end(),
        std::bind2nd(std::greater<int>(), 5));
    if (it != numbers.end())
        std::cout << "5'ten büyük ilk sayı: " << *it << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::copy - Bir aralığı başka bir yere kopyalar
     * Complexity: O(n)
     */
    std::cout << YELLOW << "\n6. std::copy kullanımı:\n" << RESET;
    std::vector<int> copied(numbers.size());
    std::copy(numbers.begin(), numbers.end(), copied.begin());
    std::cout << "Kopyalanan vector: ";
    for (size_t i = 0; i < copied.size(); ++i)
        std::cout << copied[i] << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::unique - Ardışık duplicate'leri kaldırır
     * Complexity: O(n)
     * NOT: Önce sort edilmeli tüm duplicate'leri kaldırmak için!
     */
    std::cout << YELLOW << "\n7. std::unique kullanımı:\n" << RESET;
    std::sort(numbers.begin(), numbers.end());
    std::vector<int>::iterator last = std::unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end()); // Gerçekten silmek için erase gerekli
    std::cout << "Unique elemanlar: ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * std::binary_search - Sıralı aralıkta binary search yapar
     * Complexity: O(log n)
     * DİKKAT: Container sorted olmalı!
     */
    std::cout << YELLOW << "\n8. std::binary_search kullanımı:\n" << RESET;
    bool found = std::binary_search(numbers.begin(), numbers.end(), 8);
    std::cout << "8 var mı? " << (found ? "Evet" : "Hayır") << std::endl;
}

/* ============================================================================
 * BÖLÜM 6: ITERATOR KATEGORİLERİ VE KULLANIMI
 * ============================================================================
 * 
 * Iterator'lar 5 kategoriye ayrılır:
 * 1. Input Iterator - Sadece okuma, forward only
 * 2. Output Iterator - Sadece yazma, forward only
 * 3. Forward Iterator - Okuma+yazma, forward only
 * 4. Bidirectional Iterator - Forward + backward (++, --)
 * 5. Random Access Iterator - Tüm arithmetic işlemler (+, -, <, >)
 */

void demonstrateIterators()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "ITERATOR KATEGORİLERİ VE KULLANIMI\n";
    std::cout << "========================================\n" << RESET;
    
    std::vector<int> vec;
    for (int i = 1; i <= 10; ++i)
        vec.push_back(i * 10);
    
    /* ------------------------------------------------------------------------
     * 1. NORMAL ITERATION (begin -> end)
     */
    std::cout << YELLOW << "\n1. Normal Forward Iteration:\n" << RESET;
    std::cout << "Elemanlar: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * 2. CONST ITERATION (değişiklik yapılamaz)
     */
    std::cout << YELLOW << "\n2. Const Iterator:\n" << RESET;
    std::cout << "Elemanlar (const): ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
        // *it = 999; // COMPILE ERROR! const iterator ile değişiklik yapılamaz
    }
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * 3. REVERSE ITERATION (rbegin -> rend, sondan başa)
     */
    std::cout << YELLOW << "\n3. Reverse Iterator:\n" << RESET;
    std::cout << "Elemanlar (ters): ";
    for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * 4. RANDOM ACCESS ITERATOR ÖZELLİKLERİ (sadece vector, deque'da var)
     */
    std::cout << YELLOW << "\n4. Random Access Iterator Özellikleri:\n" << RESET;
    std::vector<int>::iterator it = vec.begin();
    
    // Arithmetic operations:
    std::cout << "begin(): " << *it << std::endl;
    std::cout << "begin() + 3: " << *(it + 3) << std::endl;
    std::cout << "begin() + 7: " << *(it + 7) << std::endl;
    
    // Iterator aritmetiği:
    std::vector<int>::iterator it1 = vec.begin() + 2;
    std::vector<int>::iterator it2 = vec.begin() + 7;
    std::cout << "İki iterator arası mesafe: " << (it2 - it1) << std::endl;
    
    // Iterator karşılaştırma:
    if (it1 < it2)
        std::cout << "it1, it2'den önce geliyor" << std::endl;
    
    /* ------------------------------------------------------------------------
     * 5. BIDIRECTIONAL ITERATOR (list'te var, random access yok)
     */
    std::cout << YELLOW << "\n5. Bidirectional Iterator (List):\n" << RESET;
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i)
        lst.push_back(i * 100);
    
    std::list<int>::iterator lstIt = lst.begin();
    std::cout << "begin(): " << *lstIt << std::endl;
    ++lstIt; // OK
    std::cout << "begin() + 1 (using ++): " << *lstIt << std::endl;
    --lstIt; // OK
    std::cout << "geri (using --): " << *lstIt << std::endl;
    // lstIt + 3; // COMPILE ERROR! List'te random access yok
    
    /* ------------------------------------------------------------------------
     * 6. ITERATOR TRAITS - Iterator özelliklerini sorgulamak
     */
    std::cout << YELLOW << "\n6. Iterator ile Mesafe Hesaplama:\n" << RESET;
    std::vector<int>::iterator first = vec.begin();
    std::vector<int>::iterator last = vec.end();
    std::cout << "Vector'deki eleman sayısı (distance ile): " 
              << std::distance(first, last) << std::endl;
    
    /* ------------------------------------------------------------------------
     * 7. std::advance - Iterator'ı ilerletme
     */
    std::cout << YELLOW << "\n7. std::advance kullanımı:\n" << RESET;
    std::vector<int>::iterator advIt = vec.begin();
    std::advance(advIt, 4); // 4 adım ilerle
    std::cout << "begin()'den 4 adım sonrası: " << *advIt << std::endl;
}

/* ============================================================================
 * BÖLÜM 7: SPAN CLASS KULLANIMI (Exercise 01 konseptleri)
 * ============================================================================ */

void demonstrateSpan()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "SPAN CLASS - RANGE İŞLEMLERİ\n";
    std::cout << "========================================\n" << RESET;
    
    try
    {
        /* Test 1: Temel kullanım */
        std::cout << YELLOW << "\n1. Temel Span Kullanımı:\n" << RESET;
        SimpleSpan sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Span içeriği: ";
        sp.print();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        /* Test 2: Range ekleme - ITERATOR KULLANIMI */
        std::cout << YELLOW << "\n2. Range Ekleme ile Span:\n" << RESET;
        SimpleSpan sp2(10000);
        
        // Bir vector oluştur ve bunu span'e range olarak ekle
        std::vector<int> data;
        for (int i = 0; i < 10000; ++i)
            data.push_back(i);
        
        // DİKKAT: Burada iterator aralığı kullanıyoruz!
        // Bu, addNumber()'ı 10000 kere çağırmaktan çok daha verimli
        sp2.addRange(data.begin(), data.end());
        
        std::cout << "10000 eleman eklendi (range ile)" << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
        
        /* Test 3: Exception handling */
        std::cout << YELLOW << "\n3. Exception Handling:\n" << RESET;
        try
        {
            SimpleSpan sp3(2);
            sp3.addNumber(1);
            sp3.addNumber(2);
            sp3.addNumber(3); // Bu exception fırlatacak
        }
        catch (const std::exception& e)
        {
            std::cout << RED << "Exception yakalandı: " << e.what() << RESET << std::endl;
        }
        
        try
        {
            SimpleSpan sp4(1);
            sp4.addNumber(42);
            sp4.shortestSpan(); // Sadece 1 eleman, span hesaplanamaz
        }
        catch (const std::exception& e)
        {
            std::cout << RED << "Exception yakalandı: " << e.what() << RESET << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Beklenmeyen hata: " << e.what() << RESET << std::endl;
    }
}

/* ============================================================================
 * BÖLÜM 8: MUTANT STACK KULLANIMI (Exercise 02 konseptleri)
 * ============================================================================ */

void demonstrateMutantStack()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "MUTANT STACK - ITERABLE STACK\n";
    std::cout << "========================================\n" << RESET;
    
    /* Test 1: Normal stack işlemleri */
    std::cout << YELLOW << "\n1. Normal Stack İşlemleri:\n" << RESET;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    /* Test 2: İTERATİON! - Normal stack'te bu imkansız! */
    std::cout << YELLOW << "\n2. Stack Üzerinde İteration:\n" << RESET;
    std::cout << "Stack elemanları (alt-üst): ";
    
    /*
     * DİKKAT: Normal std::stack ile bu yapılamaz!
     * MutantStack sayesinde begin/end kullanabiliyoruz
     */
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;  // İleriletebiliyoruz
    --it;  // Geriletebiliyoruz
    
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    /* Test 3: Reverse iteration */
    std::cout << YELLOW << "\n3. Reverse Iteration:\n" << RESET;
    std::cout << "Stack elemanları (üst-alt): ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); 
         rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    /* Test 4: STL algoritmaları kullanabilme */
    std::cout << YELLOW << "\n4. STL Algoritmaları ile Kullanım:\n" << RESET;
    
    // std::find kullanalım
    MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 737);
    if (found != mstack.end())
        std::cout << "737 bulundu!" << std::endl;
    
    // std::count kullanalım
    int count = std::count(mstack.begin(), mstack.end(), 5);
    std::cout << "5 sayısı " << count << " kere geçiyor" << std::endl;
    
    /* Test 5: Normal stack'e atama yapabilme */
    std::cout << YELLOW << "\n5. Normal Stack'e Dönüşüm:\n" << RESET;
    std::stack<int> normalStack(mstack);
    std::cout << "Normal stack'in size'ı: " << normalStack.size() << std::endl;
    std::cout << "Normal stack'in top'u: " << normalStack.top() << std::endl;
    
    /* Test 6: List ile karşılaştırma (aynı çıktıyı vermeli) */
    std::cout << YELLOW << "\n6. List ile Karşılaştırma:\n" << RESET;
    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nList:        ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/* ============================================================================
 * BÖLÜM 9: EASYFIND KULLANIMI (Exercise 00 konseptleri)
 * ============================================================================ */

void demonstrateEasyfind()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "EASYFIND - TEMPLATE FUNCTION\n";
    std::cout << "========================================\n" << RESET;
    
    /* Test 1: Vector ile */
    std::cout << YELLOW << "\n1. Vector'de Arama:\n" << RESET;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 10);
    
    int result = easyfind(vec, 50);
    if (result != -1)
        std::cout << "50 bulundu, index: " << result << std::endl;
    else
        std::cout << "50 bulunamadı" << std::endl;
    
    result = easyfind(vec, 999);
    if (result != -1)
        std::cout << "999 bulundu, index: " << result << std::endl;
    else
        std::cout << RED << "999 bulunamadı" << RESET << std::endl;
    
    /* Test 2: List ile - AYNI FONKSIYON! */
    std::cout << YELLOW << "\n2. List'te Arama:\n" << RESET;
    std::list<int> lst;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i * 5);
    
    result = easyfind(lst, 25);
    if (result != -1)
        std::cout << "25 bulundu, pozisyon: " << result << std::endl;
    
    /* Test 3: Deque ile - GENE AYNI FONKSIYON! */
    std::cout << YELLOW << "\n3. Deque'de Arama:\n" << RESET;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    
    result = easyfind(deq, 200);
    if (result != -1)
        std::cout << "200 bulundu, index: " << result << std::endl;
    
    /*
     * ÖNEMLİ NOT:
     * Aynı easyfind fonksiyonu vector, list, deque gibi farklı container'larla
     * çalışıyor! Bu template'lerin gücüdür - generic programming!
     * 
     * Compiler her tip için otomatik olarak uygun versiyonu oluşturur:
     * - easyfind<std::vector<int>>
     * - easyfind<std::list<int>>
     * - easyfind<std::deque<int>>
     */
}

/* ============================================================================
 * BÖLÜM 10: İLERİ SEVİYE KONSEPTLER
 * ============================================================================ */

void demonstrateAdvancedConcepts()
{
    std::cout << BOLD << CYAN << "\n========================================\n";
    std::cout << "İLERİ SEVİYE KONSEPTLER\n";
    std::cout << "========================================\n" << RESET;
    
    /* ------------------------------------------------------------------------
     * 1. ITERATOR INVALIDATION - ÖNEMLİ KAVRAM!
     */
    std::cout << YELLOW << "\n1. Iterator Invalidation:\n" << RESET;
    std::cout << "Vector'e eleman eklerken iterator'lar geçersiz hale gelebilir!\n";
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    std::vector<int>::iterator it = vec.begin();
    std::cout << "İlk eleman: " << *it << std::endl;
    
    // Çok eleman eklersek vector reallocation yapabilir
    // Bu durumda eski iterator'lar geçersiz olur!
    for (int i = 0; i < 1000; ++i)
        vec.push_back(i);
    
    // *it; // DANGEROUS! Iterator invalidated olabilir
    
    std::cout << "Güvenli kullanım: iterator'ı yeniden al\n";
    it = vec.begin();
    std::cout << "İlk eleman (yeni iterator): " << *it << std::endl;
    
    /* ------------------------------------------------------------------------
     * 2. CONST_CAST ve CONST CORRECTNESS
     */
    std::cout << YELLOW << "\n2. Const Correctness:\n" << RESET;
    const std::vector<int> constVec(10, 42);
    
    // Const container'dan const_iterator almalıyız
    std::vector<int>::const_iterator cit = constVec.begin();
    std::cout << "Const vector'ün ilk elemanı: " << *cit << std::endl;
    // *cit = 999; // COMPILE ERROR!
    
    /* ------------------------------------------------------------------------
     * 3. MANUAL PREDICATE (Koşul Kontrolü)
     * Not: C++98'de lambda yok, bu yüzden manuel sayıyoruz
     */
    std::cout << YELLOW << "\n3. Çift Sayı Sayma (Manuel):\n" << RESET;
    
    std::vector<int> numbers;
    for (int i = 1; i <= 10; ++i)
        numbers.push_back(i);
    
    // Çift sayıları manuel say
    int evenCount = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        if (*it % 2 == 0)
            evenCount++;
    }
    std::cout << "Çift sayı adedi: " << evenCount << std::endl;
    
    /* ------------------------------------------------------------------------
     * 4. TRANSFORM - Elemanları dönüştürme
     */
    std::cout << YELLOW << "\n4. std::transform ile Dönüşüm:\n" << RESET;
    std::vector<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    source.push_back(4);
    
    std::vector<int> dest(source.size());
    
    // Her elemanı 2 ile çarp
    std::transform(source.begin(), source.end(), dest.begin(),
        std::bind2nd(std::multiplies<int>(), 2));
    
    std::cout << "Kaynak: ";
    for (size_t i = 0; i < source.size(); ++i)
        std::cout << source[i] << " ";
    std::cout << "\nHedef (x2): ";
    for (size_t i = 0; i < dest.size(); ++i)
        std::cout << dest[i] << " ";
    std::cout << std::endl;
    
    /* ------------------------------------------------------------------------
     * 5. BACK_INSERTER - Dinamik ekleme
     */
    std::cout << YELLOW << "\n5. back_inserter ile Dinamik Ekleme:\n" << RESET;
    std::vector<int> src;
    src.push_back(10);
    src.push_back(20);
    src.push_back(30);
    
    std::vector<int> dst; // Boş başlıyor
    
    // back_inserter sayesinde otomatik push_back yapılır
    std::copy(src.begin(), src.end(), std::back_inserter(dst));
    
    std::cout << "Kopyalanan: ";
    for (size_t i = 0; i < dst.size(); ++i)
        std::cout << dst[i] << " ";
    std::cout << std::endl;
}

/* ============================================================================
 * MAIN FUNCTION - TÜM DEMONSTRATİONLARI ÇALIŞTIR
 * ============================================================================ */

int main()
{
    std::cout << BOLD << GREEN;
    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                                                            ║\n";
    std::cout << "║     C++ MODULE 08 - KAPSAMLI ÖĞRENME PROGRAMI             ║\n";
    std::cout << "║                                                            ║\n";
    std::cout << "║     Containers, Iterators, Algorithms                      ║\n";
    std::cout << "║                                                            ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    std::cout << RESET;
    
    try
    {
        // Her bölümü sırayla çalıştır
        demonstrateContainers();
        demonstrateAlgorithms();
        demonstrateIterators();
        demonstrateEasyfind();
        demonstrateSpan();
        demonstrateMutantStack();
        demonstrateAdvancedConcepts();
        
        std::cout << BOLD << GREEN << "\n╔════════════════════════════════════════════════════════════╗\n";
        std::cout << "║                                                            ║\n";
        std::cout << "║     TÜM TESTLER BAŞARIYLA TAMAMLANDI! ✓                   ║\n";
        std::cout << "║                                                            ║\n";
        std::cout << "║     Artık şunları öğrendin:                                ║\n";
        std::cout << "║     • STL Container'ları (vector, list, map, vb.)         ║\n";
        std::cout << "║     • Iterator kullanımı ve kategorileri                  ║\n";
        std::cout << "║     • STL Algorithm'ları (find, sort, copy, vb.)          ║\n";
        std::cout << "║     • Template function'lar ve generic programming        ║\n";
        std::cout << "║     • Range-based operations                               ║\n";
        std::cout << "║                                                            ║\n";
        std::cout << "╚════════════════════════════════════════════════════════════╝\n" << RESET;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << "\n❌ Fatal error: " << e.what() << RESET << std::endl;
        return 1;
    }
    
    return 0;
}

/* ============================================================================
 * ÖZET VE ÖNEMLİ NOKTALAR
 * ============================================================================
 * 
 * 1. CONTAINERS:
 *    - Vector: Random access, dinamik array
 *    - List: Bidirectional, linked list, frequent insert/delete
 *    - Deque: Her iki uçtan ekleme/çıkarma
 *    - Stack: LIFO, sadece top erişim
 *    - Map: Key-value, sorted, O(log n) access
 *    - Set: Unique elements, sorted
 * 
 * 2. ITERATORS:
 *    - begin/end: Forward iteration
 *    - rbegin/rend: Reverse iteration
 *    - const_iterator: Read-only
 *    - Iterator kategorileri: input, output, forward, bidirectional, random access
 * 
 * 3. ALGORITHMS:
 *    - find, sort, reverse: Temel arama ve sıralama
 *    - copy, transform: Kopyalama ve dönüştürme
 *    - count, accumulate: Sayma ve toplama
 *    - unique, binary_search: İleri seviye operasyonlar
 * 
 * 4. BEST PRACTICES:
 *    - Doğru container'ı seç (kullanım senaryosuna göre)
 *    - const_iterator kullan (değişiklik yapmayacaksan)
 *    - Iterator invalidation'a dikkat et
 *    - STL algoritmaları kullan (kendi yazmak yerine)
 *    - Range-based operations tercih et (tek tek eklemek yerine)
 * 
 * 5. PERFORMANS:
 *    - Vector: Cache-friendly, random access O(1)
 *    - List: Insert/delete O(1) (pozisyon biliniyorsa)
 *    - Map/Set: O(log n) operations
 *    - Unordered containers (C++11): O(1) average case
 * 
 * Derleme:
 * c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o learn_module08
 * 
 * Çalıştırma:
 * ./learn_module08
 * 
 * ============================================================================ */
