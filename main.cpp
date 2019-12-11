#include <iostream>
using namespace std;
template <typename T>
class Vector{
private:
	int size_n;//размер массива
	int pos;//индекс указателя до которого все заполнено
	T *array=new T[0];//массив с элементами
public:
	Vector():size_n(0){//конструктор по умолчанию
	}
	Vector(int l):size_n(l){//иницилизация вектора
		if (l>0)
		{
			array =(T*)realloc(array,sizeof(T)*l);//увеличение размера массива под установленный размен
		}
		pos=0;//указание на первый элемент
	}
	void add(){
		T item;
		if (pos>size_n)//проверка на нахождение внутри массива
		{
		array=(T*)realloc(array,sizeof(T)* pos);//увеличение массива под подходящий размер
		size_n=pos;//увеличиваем размер под позицию
		}
		array[pos]=item;//присваивание элемента
		
		pos++;//переход позиции
	}
	void add(T item){//аналогично с предыдущей функции
		if (pos>size_n)//увеличение массива если индекс больше размера
		{
		array=(T*)realloc(array,sizeof(T)* pos);
		size_n=pos;
		}
		array[pos]=item;
		pos++;
	}
	int size(){
		return pos;//возвращение размера
	}
	T operator[](int item)
    {
      return array[item];//возвращение элемента по скобкам
    }

    bool empty(){
    	return ((size_n==0)||(pos==0))?true:false;//проверка на пустоту
    }
    void erase(int k){//удаление элемента по индексу
    	T buf=array[0];
    	if ((k>=0)&&(k<pos))//нахождение индексе внутри возможного массива
    	{
    	for (int i = k; i < size()-1; ++i)//перенос элемента в конец массива с уменьшением размера
    	{
    		buf=array[i];
    		array[i]=array[i+1];
    		array[i+1]=buf;
    	}
    	array=(T*)realloc(array,sizeof(T)*(pos-1));//уменьшение размера
    	size_n-=1;//уменьшение размера
    	pos--;//перенос позиции назад
    	}
    	else{
    		cout<<"Index is not in array"<<endl;//вывод если индекс вне массива
    	}
    }
	~Vector(){
		if (!empty())
		{
			delete [] array;//отчистка не пустого массива
			cout<< "Memory is free"<<endl;
		}

	}
	friend ostream& operator<< (std::ostream &out, Vector &point){
    if (!point.empty())//определение вывода
    {
    cout<<"---------"<<endl;
     cout<<"Vector list:"<<endl;
     for (int i = 0; i < point.size(); ++i)
     {
     	out<<i+1<<")"<<point.array[i]<<endl;
     } 
    }
    else{
    	out<<"Vector is empty!"<<endl;
    }
    return out;
    }
};
class Money{
private:
	long r;
	int k;
public:
	Money(int a,int b):r(a+b/100),k(b%100){}//конструктор класс Money
	Money(){//конструктор по-умолчанию класс Money
		cout<<"Enter rubly: ";
		cin>>r;
		cout<<"Enter kopeyki: ";
		cin>>k;
	}
	void print(){
		cout<<r<<" "<<k<<endl;//вывод полей класса
	}
	Money& operator=(const Money &drob){//оператор присваивания
		r = drob.r;
		k = drob.k;
		return *this;
	}
	friend ostream& operator<< (std::ostream &out, const Money &point){
     	out<<point.r<<","<<point.k;//определение оператора вывода 
    return out;
    }
};
int main(){
	Vector<double> g1(10);
	g1.add(4.56);
	g1.add(5.234);
	g1.add(7.12);
	g1.add(6.123);
	g1.add(7.965);
	cout<<g1;
	cout<<"double elemnts:"<<endl;
	cout<<g1[2]<<" "<<g1[3]<<endl;
	Vector<int> g(10);
	g.add(4);
	g.add(5);
	g.add(7);
	g.add(6);
	g.add(7);
	g.add(8);
	g.add(6);
	g.add(10);
	cout<<g;
	cout<<"int elemnts:"<<endl;
	cout<<g[5]<<" "<<g[3]<<endl;
	cout<<"Delete twe elemnts from array";
	g.erase(2);
	g.erase(6);
	cout<<g;
	Vector <Money> a(5);
	Money s(2,4);
	Money s1(3,1);
	Money s2(1,1);
	a.add(s);
	a.add(s1);
	cout<<a;
	a.add(s2);
	a.erase(2);
	cout<<a; 
	return 0;
}
