1. 定义buff[0]为上面的缓冲区，buff[1]为下面的缓冲区
2. 设buffempty[0] = n, buffull[1] = 0为 $P_a$ 的私有信号量
3. 设buffempty[1] = n, buffull[0] = 0为 $P_b$ 的私有信号量

```
send(i, m):
begin
	P(buffempty[i]);
	buff[i].push(m);
    V(buffull[i]);
end

receive(i, m):
begin
	P(buffull[i]);
	m = buff[i].front();
	buff[i].pop();
	V(buffempty[i]);
end
```
