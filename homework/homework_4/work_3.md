```cpp
/*

互斥信号量mutex表示盘子是否可用，其初值为1；



同步信号量orange表示盘中桔子数目，其初值为0；



同步信号量apple表示盘中苹果数目，其初值为0。

*/



Var mutex,apple,orange : semaphore:=1,0,0; 



father:

  begin

​     repeat

​     wait(mutex);

​    

​     放水果;

​    

​     if(orange)

​        signal(orange);

​     else

​        signal(apple);

​     fi



​     signal(mutex);

​     until false

  end



son:

   begin

​     repeat

​     wait(orange); 

​     wait(mutex);

​    

​     从盘中取出桔子;

​    

​     signal(mutex);

​    

​     吃桔子;

​     until false

   end



daughter:

   begin

​     repeat

​     wait(apple); 

​     wait(mutex);

​    

​     从盘中取出苹果;

​    

​     signal(mutex);

​    

​     吃苹果;

​     until false

   end

```