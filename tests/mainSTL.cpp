#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <utility>

template<class Q, class U>
        void printmaprev(std::map<Q, U> &l)
        {
            typename std::map <Q, U> :: reverse_iterator it1 = l.rbegin();
            typename std::map <Q, U> :: reverse_iterator it2 = l.rend();
            std::cout << "А вот все отсортированно: " << std::endl;
            for (int i = 0; it1 != it2; it1++, i++) {  // выводим их
                //        std::cout  << ") Ключ " << it1->first << ", значение " << it1->second << std::endl;
                std::cout  << i << ") Ключ " << it1->first << ", значение " << it1->second << std::endl;
            }
        }
        template<class Q, class U>
                void printmapconst(std::map<Q, U> &l)
                {
                    typename std::map <Q, U> :: const_iterator it1;
                    it1 = l.end();
                    typename std::map <Q, U> :: const_iterator it2;
                    it2 = l.begin();
                    std::cout << "А вот все отсортированно: " << std::endl;
                    for (int i = 0; it2 != it1; it2++, i++) {  // выводим их
                        //        std::cout  << ") Ключ " << it1->first << ", значение " << it1->second << std::endl;
                        std::cout  << i << ") Ключ " << it2->first << ", значение " << it2->second << std::endl;
                    }
                }
                template<class Q, class U>
                        void printmap1(std::map<Q, U> &l)
                        {
                            typename std::map <Q, U> :: iterator it1 = l.find(200);
                            typename std::map <Q, U> :: iterator it2 = l.begin();
                            std::cout << "А вот все отсортированно: " << std::endl;
                            for (int i = 0; it2 != it1; it1--, i++) {  // выводим их
                                //        std::cout  << ") Ключ " << it1->first << ", значение " << it1->second << std::endl;
                                std::cout  << i << ") Ключ " << it1->first << ", значение " << it1->second << std::endl;
                            }
                        }
                        template<typename Q, typename U>
                        void printmap(std::map<Q, U> &l)
                        {
                            typename std::map < Q,  U> :: iterator it1 = l.end();
                            typename std::map <Q, U> :: iterator it2 = l.begin();
                            std::cout << "А вот все отсортированно: " << std::endl;
                            for (int i = 0; it2 != it1; it2++, i++) {  // выводим их
                                //        std::cout  << ") Ключ " << it1->first << ", значение " << it1->second << std::endl;
                                std::cout  << i << ") Ключ " << it2->first << ", значение " << it2->second << std::endl;
                            }
                        }
template<typename T>
void print_vec1(std::vector<T>& vec)
{
    int p =0;
    typename std::vector<T>::iterator x = vec.begin();
    //    std::cout << *x << std::endl;
    typename std::vector<T>::iterator x1 = vec.end();
    x1--;
    for (int i = 0; x != x1; i++, x1--)
    {
        std::cout << " |" << i << ") " << *x1;
        p = i;
    }
    std::cout << " |" << ++p << ") " << *x1;
    std::cout << '\n';
}
template<typename T>
void print_vec(std::vector<T>& vec)
{
    typename std::vector<T>::iterator x = vec.begin();
//    std::cout << *x << std::endl;
    typename std::vector<T>::iterator x1 = vec.end();
    for (int i = 0; x != x1; i++, ++x)
    {
        std::cout << " |" << i << ") " << *x;
    }
    std::cout << '\n';
}
template<typename T>
void cappa(std::vector<T> &h)
{
    std::cout << "SIZE:  " << h.size() << "   CAPACITY: " << h.capacity() << std::endl;
}

void mainstack()
{
    std::cout << "--------------------------------STACK__________________________________" << std::endl;
    std::cout << std::endl;
    std::string j1 = "fgtht";
    std::string j2 = "ooooo";
    std::string j3 = "aaaaa";
    std::string j4 = "11111";
    std::string j5 = "ioioioi";
    std::stack<std::string, std::vector<std::string> > jok;
    jok.push(j1);
    jok.push(j2);
    jok.push(j3);
    std::cout << jok.top() << std::endl;
    std::cout << jok.empty() << std::endl;
    jok.push(j4);
    jok.pop();
    std::cout << jok.top() << std::endl;
    std::cout << jok.size() << std::endl;
    std::stack<std::string, std::vector<std::string> > vanda(jok);
    std::string j6 = "lllllll";
    vanda.pop();
    vanda.push(j6);
    std::cout << vanda.top() << std::endl;
    std::cout << "!= " << (vanda != jok) << std::endl;
    std::cout << "> " << (vanda > jok) << std::endl;
    std::cout << ">= " << (vanda >= jok) << std::endl;
    std::cout << "< " << (vanda < jok) << std::endl;
    std::cout << "<= " << (vanda <= jok) << std::endl;
    std::cout << "== " << (vanda == jok) << std::endl;
    std::deque<int> ui;
    ui.push_back(35);
    ui.push_back(99);
    ui.push_back(-35);
    ui.push_front(12);
    std::stack<int, std::deque<int> > l(ui);
    std::cout << l.top() << std::endl;
    std::stack<int, std::list<int> > l1;
    l1.push(78);
    l1.push(-456);
    std::cout << l1.top() << std::endl;
}

void mainvector()
{
    std::cout << "--------------------------------VECTOR__________________________________" << std::endl;
    std::cout << std::endl;
            std::vector<int> gg;
    cappa(gg);
    gg.push_back(40);
    cappa(gg);
    gg.push_back(40);
    cappa(gg);
    gg.push_back(40);
    cappa(gg);
    gg.clear();
    std::cout << "|resise| :" << std::endl;
    gg.resize(10);
    print_vec(gg);
    cappa(gg);
    gg.resize(18);
    cappa(gg);
    std::cout << "|reserve| :" << std::endl;
    gg.reserve(25);
    cappa(gg);
    print_vec(gg);
    gg.resize(12);
    cappa(gg);
    std::cout << "|resise + val| :" << std::endl;
    gg.resize(15, 37);
    cappa(gg);
    print_vec(gg);
    gg.resize(8, -15);
    cappa(gg);
    print_vec(gg);
    gg.reserve(10);
    cappa(gg);
    std::cout << "|push_back| :" << std::endl;
    gg.resize(23);
    cappa(gg);
    gg.push_back(40);
    cappa(gg);
    print_vec(gg);
    gg.push_back(41);
    cappa(gg);
    print_vec(gg);
    gg.push_back(42);
    cappa(gg);
    print_vec(gg);
    gg.pop_back();
    gg.pop_back();
    gg.pop_back();
    cappa(gg);
    std::cout << "|assign| :" << std::endl;
    gg.assign(15, 111);
    cappa(gg);
    print_vec(gg);
    gg.assign(18, -2);
    cappa(gg);
    print_vec(gg);
    std::cout << "|empty| : " << gg.empty() << std::endl;
    std::cout << "|[]| : " << gg[3] << gg[4] << gg[999] << std::endl;
    gg.push_back(41);
    // std::cout << "|data| : " << gg.data() << std::endl;
    std::cout << "|back| : " << gg.back() << std::endl;
    std::cout << "|front| : " << gg.front() << std::endl;
//    std::cout << "|at| : " << gg.at(-2) << std::endl;
    std::cout << "|at| : " << gg.at(4) << std::endl;
    gg.assign(8, -2);
    std::cout << "|insert + val| :" << std::endl;
    std::vector<int>::iterator it1 = gg.begin();
    std::cout << *it1 << std::endl;
    it1++;
    it1++;
    it1 = gg.insert(it1, 66);
    cappa(gg);
    print_vec(gg);
    std::cout << *it1 << std::endl;
    it1 = gg.end();
    it1 = gg.insert(it1, 77);
    cappa(gg);
    print_vec(gg);
    it1 = gg.begin();
    it1 = gg.insert(it1, 77);
    cappa(gg);
    print_vec(gg);
    it1++;
    it1++;
    std::cout << "|insert + count + val| :" << std::endl;
    gg.insert(it1, 2,55);
    cappa(gg);
    print_vec(gg);
    print_vec1(gg);
    std::cout << "|[]=| :" << std::endl;
    gg[7] = 44;
    gg[9] = 323;
    gg[10] = -984;
    print_vec(gg);
    gg[100] = 4565;
    print_vec(gg);
    std::vector<int> hg1(3, 4);
    std::vector<int>::iterator ity;
    ity = hg1.begin();
    ity = hg1.insert(ity, 6);
    ity = hg1.insert(ity, 6);
    ity = hg1.insert(ity, 6);
    ity = hg1.insert(ity, 6);
    ity = hg1.insert(ity, 6);
    ity = hg1.insert(ity, 6);
    cappa(hg1);
    std::cout << "|iterator operations| :" << std::endl;
    std::vector<int>::const_iterator rr = gg.begin();
    std::vector<int>::const_iterator r1;
    rr++;
    std::cout << *rr << std::endl;
    rr += 3;
    std::cout << *rr << std::endl;
    rr--;
    std::cout << *rr << std::endl;
    std::cout << rr[4] << std::endl;
    r1 = rr + 6;
    std::cout << *r1 << std::endl;
    rr += 6;
    rr -= 2;
    std::cout << *rr << std::endl;
    r1 = rr - 2;
    std::cout << *r1 << std::endl;
    std::cout << "|reverse iterator| :" << std::endl;
    std::vector<int>::reverse_iterator ee = gg.rbegin();
    std::vector<int>::reverse_iterator e1;
    e1 = gg.rend();
    std::cout << "||" << *ee << std::endl;
    ee++;
    std::cout << "||" << *ee << std::endl;
    ee += 3;
    std::cout << *ee << std::endl;
    ee--;
    std::cout << *ee << std::endl;
    std::cout << ee[4] << std::endl;
    e1 = ee + 6;
    std::cout << *e1 << std::endl;
    ee += 6;
    ee -= 2;
    std::cout << *ee << std::endl;
    e1 = ee - 2;
    std::cout << *e1 << std::endl;
    std::cout << ">" << (r1 > rr) << std::endl;
    std::cout << "<=" << (r1 <= rr) << std::endl;
    std::cout << "!+" << (r1 != rr) << std::endl;
    std::cout << ">" << (e1 > ee) << std::endl;
    std::cout << "==" << (e1 == ee) << std::endl;
    std::cout << "<" << (e1 < ee) << std::endl;
    std::cout << "<=" << (e1 <= ee) << std::endl;
    std::cout << "|construct + count + val| :" << std::endl;
    std::vector<int> jj(10, 55);
    cappa(jj);
    print_vec(jj);
    rr = gg.begin();
    std::vector<int>::iterator pp = jj.begin();
    pp++;
    pp = jj.insert(pp, 77);
    pp = jj.insert(pp, 78);
    pp = jj.insert(pp, 79);
    cappa(jj);
    r1 = gg.end();
    r1 -= 3;
    std::cout << "|insert + iterator + iter + iter| :" << std::endl;
    std::vector<int> pa(24, -55);
    std::vector<int> pi(3, -45);
    std::vector<int>::iterator da1 = pa.begin();
    std::vector<int>::iterator da2 = pa.end();
    std::vector<int>::iterator da3 = pi.begin();
    da3++;
    pi.insert(da3, da1, da2);
    std::cout << "|pi| :" << std::endl;
    cappa(pi);
    print_vec(pi);
    std::cout << "|construct + iterator| :" << std::endl;
    std::vector<int> bah(rr, r1);
    cappa(bah);
    print_vec(bah);
    std::cout << "|assign + iter| :" << std::endl;
    da3 = pi.begin();
    da3 += 8;
    da2 = pi.begin();
    bah.assign(da2, da3);
    cappa(bah);
    print_vec(bah);
    std::cout << ">" << (pi > bah) << std::endl;
    std::cout << ">=" << (pi <= bah) << std::endl;
    std::cout << "!=" << (pi != bah) << std::endl;
    std::cout << "==" << (pi == bah) << std::endl;
    std::cout << "<" << (pi < bah) << std::endl;
    std::cout << "<=" << (pi <= bah) << std::endl;
    std::cout << "|swap| :" << std::endl;
    pi.swap(bah);
    print_vec(bah);
    print_vec(pi);
    std::cout << "|erase iter| :" << std::endl;
    print_vec(gg);
    da1 = gg.begin();
    da1 += 4;
    da1 = gg.erase(da1);
    da1 = gg.erase(da1);
//    da1 += 4;
    da1 = gg.erase(da1);
    print_vec(gg);
    std::cout << *da1 << std::endl;
    cappa(gg);
    gg.push_back(345);
    gg.push_back(-467);
    gg.push_back(4343);
    gg.push_back(93543);
    da1 = gg.begin();
    da1+= 4;
    da2 = gg.end();
    //    dd2--;
    print_vec(gg);
    std::cout << "|erase iter iter| :" << std::endl;
    da1 = gg.erase(da1, da2);
    print_vec(gg);
    std::cout << *da1 << std::endl;
    cappa(gg);
    std::cout << "|constructor copy| :" << std::endl;
    std::vector<int> tanos(gg);
    gg.clear();
    cappa(tanos);
    print_vec(tanos);
    std::vector<int> tanos1;
    da1 = pi.begin();
    da2 = pi.end();
    tanos1.assign(da1, da2);
    cappa(tanos1);
    print_vec(tanos1);
    tanos = tanos1;
    print_vec(tanos);
    std::cout << "++++++++++++++++" << std::endl;
}

void mainmap()
{
    std::cout << "--------------------------------MAP__________________________________" << std::endl;
    std::cout << std::endl;
                            std::cout << "|insert []= | " << std::endl;
                            std::map<int, int> l;
                            int g = 5;
                            std::pair<int ,int> j(g, 12);
                            std::pair<int ,int> j1(2, 222);
                            std::pair<int ,int> j4(20, 18);
                            std::pair<int ,int> j2(4, 14);
                            std::pair<int ,int> j3(6, 13);
                            std::pair<int ,int> j5(34, 13);
                            std::pair<int ,int> j6(78, 13);
                            std::pair<int ,int> j7(23, 13);
                            std::pair<int ,int> j8(26, 13);
                            std::pair<int ,int> j9(-34, 90);
                            l.insert(j);
                            l.insert(j1);
                            l[34] = 4565;
                            l[111] = 4355;
                            l[200] = -3434;
                            l[-12] = -444;
                            l[25] = -644;
                            l.insert(j4);
                            l.insert(j3);
                            l.insert(j5);
                            l.insert(j6);
                            l.insert(j7);
                            l.insert(j8);
                            printmap(l);
                            std::map <int, int> :: iterator u1 = l.begin();
                            std::map <int, int> :: iterator u2 = l.end();
                            u1 = l.find(4);
                            std::cout << "|iterator find| " << u1->second << std::endl;
                            std::map <int, int> :: const_iterator h1 = l.begin();
                            std::map <int, int> :: const_iterator h2;
                            h2 = l.find(111);
                            h1 = h2;
                            std::cout << "|const_iterator find| " << h2->second << std::endl;
                            std::cout << "|const_iterator find| " << h1->second << std::endl;
                            std::cout << "|size| " << l.size() << std::endl;
                            u1 = l.find(23);
                            std::cout << "|insert iter-key| " << std::endl;
                            u1 = l.insert(u1, j2);
                            std::cout << "|iterator insert| " << u1->first << std::endl;
                            u1++;
                            u1 = l.insert(u1, j9);
                            std::cout << "|iterator insert| " << u1->first << std::endl;
                            printmap(l);
                            printmap1(l);
                            std::cout << "|[]| " << l[34] << "\t" << l[111] << std::endl;
                            std::cout << "|count| " << l.count(333) << "\t" << l.count(34) << std::endl;
                            std::map <int, int> :: reverse_iterator u3 = l.rbegin();
                            std::map <int, int> :: const_reverse_iterator pp3 = l.rbegin();
                            std::cout << "|reverse_iter| " << u3->first << "        "<< u3->second << pp3->first << std::endl;
                            std::cout << "|insert iter-iter| " << std::endl;
                            u1 = l.find(6);
                            u2 = l.find(34);
                            std::map <int, int> oleg;
                            oleg.insert(u1, u2);
                            printmap(oleg);
                            // std::cout << "|at| " << l.at(6) << std::endl;
                            //    std::cout << "at " << l.at(999) << std::endl;
                            std::cout << "|empty| " << l.empty() << std::endl;
                            std::map <int, int> :: iterator u4 = l.lower_bound(31);
                            std::cout << "|lower_bound| " << u4->first << std::endl;
                            u4 = l.lower_bound(-8);
                            std::cout << "|lower_bound| " << u4->first << std::endl;
                            u4 = l.lower_bound(8);
                            std::cout << "|lower_bound| " << u4->first << std::endl;
                            u4 = l.lower_bound(5);
                            std::cout << "|lower_bound| " << u4->first << std::endl;
                            u4 = l.lower_bound(25);
                            std::cout << "|lower_bound| " << u4->first << std::endl;
                            std::map <int, int> :: iterator u5 = l.upper_bound(31);
                            std::cout << "|upper_bound| " << u5->first << std::endl;
                            u5 = l.upper_bound(-8);
                            std::cout << "|upper_bound| " << u5->first << std::endl;
                            u5 = l.upper_bound(8);
                            std::cout << "|upper_bound| " << u5->first << std::endl;
                            u5 = l.upper_bound(5);
                            std::cout << "|upper_bound| " << u5->first << std::endl;
                            u5 = l.upper_bound(25);
                            std::cout << "|upper_bound| " << u5->first << std::endl;
                            std::cout << "|erase iter| " << std::endl;
                            u4 = l.upper_bound(30);
                            l.erase(u4);
                            printmap(l);
                            std::cout << "|print const iter| " << std::endl;
                            printmapconst(l);
                            std::cout << "|print rev iter| " << std::endl;
                            printmaprev(l);
                            std::pair <std::map <int, int> :: iterator, std::map <int, int> :: iterator> o1(u4, u5);
                            o1 = l.equal_range(5);
                            std::cout << "|equal_range| " << o1.first->first  << "\t" << o1.second->first<< std::endl;
                            o1 = l.equal_range(23);
                            std::cout << "|equal_range| " << o1.first->first  << "\t" << o1.second->first<< std::endl;
                            std::cout << "|erase key| " << std::endl;
                            l.erase(111);
                            l.erase(200);
                            l.erase(26);
                            l.erase(34);
                            printmap(l);
                            u1 = l.begin();
                            u2 = l.end();
                            std::map<int, int> l1(u1, u2);
                            std::cout << "|construct_iterator| " << std::endl;
                            printmap(l1);
                            std::map<int, int> l2;
                            std::pair<int ,int> ty1(6, 3);
                            std::pair<int ,int> ty2(2, 89);
                            std::pair<int ,int> ty3(89, 33333);
                            l2.insert(ty1);
                            l2.insert(ty2);
                            l2.insert(ty3);
                            std::cout << "== " << (l2 == l) << std::endl;
                            std::cout << "<= " << (l2 <= l) << std::endl;
                            std::cout << "< " << (l2 < l) << std::endl;
                            std::cout << ">= " << (l2 >= l) << std::endl;
                            std::cout << "> " << (l2 > l) << std::endl;
                            std::cout << "!= " << (l2 != l) << std::endl;
                            l[111] = 4355;
                            l[200] = -3434;
                            l.insert(j8);
                            l.insert(j5);
                            u4 = l.upper_bound(5);
                            u5 = l.upper_bound(30);
                            u1 = l.begin();
                            u2 = l.end();
                            std::map<int, int> l3(u1, u2);
                            std::cout << "|erase iter iter| " << std::endl;
                            l.erase(u4, u5);
                            printmap(l);
                            std::cout << "|clear| " << std::endl;
                            l.clear();
                            printmap(l);
                            l3.swap(l);
                            std::cout << "|swap| " << std::endl;
                            printmap(l3);
                            printmap(l);
                            std::cout << "|copyconstruct | " << std::endl;
                            std::map<int, int> boris(l);
                            l.clear();
                            std::cout << "|boris:| " <<std::endl;
                            printmap(boris);
                            std::cout << "++++++++++++++++++++++++" << std::endl;
}

int main()
{
    mainmap();
    mainstack();
    mainvector();
}