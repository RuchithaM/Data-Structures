//STL consists of 3 components
 //   1.Container     Array ,Linkedlist
 //   2.Iterator      Helps to travel in container
 //   3.Algorithm     sorting reverse                             These components forms the STL library

/* <array>
        1.syntax: std::array<T,N> array_name;  where T is datatype, N is  number of element
        2.Array size is neede in compile time.
        3.In traditional array when we pass array to a function we acctuly pass the pointer not the array.we are not able to find the len of array using pointer
        but in this method assige by value is acctually by value.(we pass the copy of array. pass by value) 
        4. Acess element 
            1. at()
            2. []
            3. front()
            4. back()
            5. data() give the address of the array (give access to the underlaying array)
*/

 #include<iostream>
 #include<array>
 using namespace std;

 int main()
 {

     std::array<int,10>myarray {1,2,3,4,5,6,7,8,9,10};
     std::array<int,10>myarray1= {1,2,3,4,5,6,7,8,9,10};
     std::array<int,10>myarray2;
     myarray2= {1,2,3,4,5,6,7,8,9,10};
     //myarray.fill(10);
    for(auto it=myarray.begin(); it!=(myarray.end())-1;++it) cout<<*(it)<<endl;
    cout<<myarray.at(3)<<endl;
    cout<<myarray[3]<<endl;
    cout<<(myarray.front())+2<<endl;
    cout<<myarray.back()<<endl;
    cout<<myarray.data()<<endl;
    cout<<&myarray;



     return 0;
 } 
