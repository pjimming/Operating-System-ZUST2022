x86架构中对内存的管理使用两种方式，即分段和分页


在x86架构中内存被分为三种形式，分别是逻辑地址（Logical Address），线性地址（Linear Address）和物理地址（Physical Address）。如上图所示，通过分段可以将逻辑地址转换为线性地址，而通过分页可以将线性地址转换为物理地址。



逻辑地址由两部分构成，一部分是段选择器（Segment Selector），一部分是偏移（Offset）。



段选择符存放在段寄存器中，如CS（存放代码段选择符）、SS（存放堆栈段选择符）、DS（存放数据段选择符）和ES、FS、GS（一般也用来存放数据段选择符）等；偏移与对应段描述符（由段选择符决定）中的基地址相加就是线性地址。



全局描述符表（Global Descriptor Table）需要OS在初始化时创建（每个CPU都有一张，基本内容大致相同，除了少数几项如TSS），创建好后将表的地址（这是个线性地址）放到全局描述符寄存器中（GDTR），这通过LGDT和SGDT指令来完成。上图只展示了全局描述符表，其实还有一种局部描述符表（Local Descriptor Table），结构与全局描述符表一致，当进程需要使用除了放在全局描述符表中的段之外的段时，就需要自己创建局部描述符表，这个用的不多，先不关注。



OS需要做的就是创建全局描述符表和提供逻辑地址，之后的分段操作x86的CPU会自动完成，并找到对应的线性地址。



对于全局描述符表中的段描述符表（Segment Descriptor）后面会详细介绍。



从线性地址到物理地址的转换也是CPU自动完成的，不过转化时使用的表（就是上图中的Page Directory和Page Table等（很多时候不只两张））也需要OS提供，对于表的创建后续也会详细介绍。



有几点需要注意：



1. 在x86架构中，分段是强制的，并不能关闭，而分页是可选的；



2. 以上是保护模式下的内存管理，在实模式下并不是这样；



3. 上述的内存管理机制通常在OS下实现，BIOS/UEFI下也不会使用（当前的UEFI应该是没有使用分页，待确定，不过可以确定的是UEFI下是可以直接访问物理地址的）；

