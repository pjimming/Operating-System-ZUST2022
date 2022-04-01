1. `pwd`

2. `ls -a`

3. `ls /`

4. `mkdir tmp, ls -l tmp`

5. `pwd, ln -s 输入[pwd]的内容 /`

6. `cd tmp/`

7. `cp /etc/mail/sendmail.cf ./`

8. `mv sendmail.cf test.file`

9. `vim test.file`, 打开后在命令模式输入G定位到最后一行，按i键输入This is a editing test.，再按esc键返回命令模式，输入:wq保存退出

10. vim中:split 横向分屏 :vsplit 竖向分屏  终端内more test.file

11. `find / -name test.file`   `find / -type -name tmp`

12. `ln -s test.file /test.file`

13. `tar -zcvf tmp.tar.gz tmp/`

14. `rm test.file`

15. `rm -rf tmp`