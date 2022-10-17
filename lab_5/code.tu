// обработка начального состояния

00, ,<,01

// переход к началу числа

01,0,<,01
01,1,<,01
01,2,<,01
01,3,<,01
01,4,<,01
01,5,<,01
01,6,<,01
01,7,<,01
01, ,>,02

// стираем цифру из первоначального числа

02,0, ,0cl
02,1, ,1cl
02,2, ,2cl
02,3, ,3cl
02,4, ,4cl
02,5, ,5cl
02,6, ,6cl
02,7, ,7cl
02, ,>,pre_end

// переход в конец ответа и завершение программы

end, , ,end
end,0,>,end
end,1,>,end
end,2,>,end
end,3,>,end
end,4,>,end
end,5,>,end
end,6,>,end
end,7,>,end

// отбрасываем незначащие нули

pre_end,0, ,pre_end
pre_end,1,1,end
pre_end, ,>,pre_end_isc0

pre_end_isc0, ,0,end
pre_end_isc0,0,0,pre_end
pre_end_isc0,1,1,pre_end
pre_end_isc0,2,2,pre_end
pre_end_isc0,3,3,pre_end
pre_end_isc0,4,4,pre_end
pre_end_isc0,5,5,pre_end
pre_end_isc0,6,6,pre_end
pre_end_isc0,7,7,pre_end



// переход на 1 цифру вправо, чтобы пройти пробел, после затирания числа

0cl, ,>,0r
1cl, ,>,1r
2cl, ,>,2r
3cl, ,>,3r
4cl, ,>,4r
5cl, ,>,5r
6cl, ,>,6r
7cl, ,>,7r

// переход в правый конец числа

0r,0,>,0r
0r,1,>,0r
0r,2,>,0r
0r,3,>,0r
0r,4,>,0r
0r,5,>,0r
0r,6,>,0r
0r,7,>,0r
0r, ,>,0pa

1r,0,>,1r
1r,1,>,1r
1r,2,>,1r
1r,3,>,1r
1r,4,>,1r
1r,5,>,1r
1r,6,>,1r
1r,7,>,1r
1r, ,>,1pa

2r, ,>,2pa
2r,0,>,2r
2r,1,>,2r
2r,2,>,2r
2r,3,>,2r
2r,4,>,2r
2r,5,>,2r
2r,6,>,2r
2r,7,>,2r

3r, ,>,3pa
3r,1,>,3r
3r,0,>,3r
3r,2,>,3r
3r,3,>,3r
3r,4,>,3r
3r,5,>,3r
3r,6,>,3r
3r,7,>,3r

4r, ,>,4pa
4r,0,>,4r
4r,1,>,4r
4r,2,>,4r
4r,3,>,4r
4r,4,>,4r
4r,5,>,4r
4r,6,>,4r
4r,7,>,4r

5r, ,>,5pa
5r,0,>,5r
5r,1,>,5r
5r,2,>,5r
5r,3,>,5r
5r,4,>,5r
5r,5,>,5r
5r,6,>,5r
5r,7,>,5r

6r, ,>,6pa
6r,0,>,6r
6r,1,>,6r
6r,2,>,6r
6r,3,>,6r
6r,4,>,6r
6r,5,>,6r
6r,6,>,6r
6r,7,>,6r

7r, ,>,7pa
7r,0,>,7r
7r,1,>,7r
7r,2,>,7r
7r,3,>,7r
7r,4,>,7r
7r,5,>,7r
7r,6,>,7r
7r,7,>,7r

// печать скопированной цифры в двоичной системе

0pa, ,0,0pa_2
0pa_2,0,>,0pa_3
0pa_3, ,0,0pa_4
0pa_4,0,>,0pa_5
0pa_5, ,0,0lf
0pa,0,>,0pa
0pa,1,>,0pa
0pa,2,>,0pa
0pa,3,>,0pa
0pa,4,>,0pa
0pa,5,>,0pa
0pa,6,>,0pa
0pa,7,>,0pa
0pa,8,>,0pa

1pa, ,0,1pa_2
1pa_2,0,>,1pa_3
1pa_3, ,0,1pa_4
1pa_4,0,>,1pa_5
1pa_5, ,1,1lf
1pa,0,>,1pa
1pa,1,>,1pa
1pa,2,>,1pa
1pa,3,>,1pa
1pa,4,>,1pa
1pa,5,>,1pa
1pa,6,>,1pa
1pa,7,>,1pa

2pa, ,0,2pa_2
2pa_2,0,>,2pa_3
2pa_3, ,1,2pa_4
2pa_4,1,>,2pa_5
2pa_5, ,0,2lf
2pa,0,>,2pa
2pa,1,>,2pa
2pa,2,>,2pa
2pa,3,>,2pa
2pa,4,>,2pa
2pa,5,>,2pa
2pa,6,>,2pa
2pa,7,>,2pa

3pa, ,0,3pa_2
3pa_2,0,>,3pa_3
3pa_3, ,1,3pa_4
3pa_4,1,>,3pa_5
3pa_5, ,1,3lf
3pa,0,>,3pa
3pa,1,>,3pa
3pa,2,>,3pa
3pa,3,>,3pa
3pa,4,>,3pa
3pa,5,>,3pa
3pa,6,>,3pa
3pa,7,>,3pa

4pa, ,1,4pa_2
4pa_2,1,>,4pa_3
4pa_3, ,0,4pa_4
4pa_4,0,>,4pa_5
4pa_5, ,0,4lf
4pa,0,>,4pa
4pa,1,>,4pa
4pa,2,>,4pa
4pa,3,>,4pa
4pa,4,>,4pa
4pa,5,>,4pa
4pa,6,>,4pa
4pa,7,>,4pa

5pa, ,1,5pa_2
5pa_2,1,>,5pa_3
5pa_3, ,0,5pa_4
5pa_4,0,>,5pa_5
5pa_5, ,1,5lf
5pa,0,>,5pa
5pa,1,>,5pa
5pa,2,>,5pa
5pa,3,>,5pa
5pa,4,>,5pa
5pa,5,>,5pa
5pa,6,>,5pa
5pa,7,>,5pa

6pa, ,1,6pa_2
6pa_2,1,>,6pa_3
6pa_3, ,1,6pa_4
6pa_4,1,>,6pa_5
6pa_5, ,0,6lf
6pa,0,>,6pa
6pa,1,>,6pa
6pa,2,>,6pa
6pa,3,>,6pa
6pa,4,>,6pa
6pa,5,>,6pa
6pa,6,>,6pa
6pa,7,>,6pa

7pa, ,1,7pa_2
7pa_2,1,>,7pa_3
7pa_3, ,1,7pa_4
7pa_4,1,>,7pa_5
7pa_5, ,1,7lf
7pa,0,>,7pa
7pa,1,>,7pa
7pa,2,>,7pa
7pa,3,>,7pa
7pa,4,>,7pa
7pa,5,>,7pa
7pa,6,>,7pa
7pa,7,>,7pa

// переходим влево до первоначального числа

0lf, ,<,0fst
0lf,0,<,0lf
0lf,1,<,0lf
0lf,2,<,0lf
0lf,3,<,0lf
0lf,4,<,0lf
0lf,5,<,0lf
0lf,6,<,0lf
0lf,7,<,0lf

1lf, ,<,1fst
1lf,0,<,1lf
1lf,1,<,1lf
1lf,2,<,1lf
1lf,3,<,1lf
1lf,4,<,1lf
1lf,5,<,1lf
1lf,6,<,1lf
1lf,7,<,1lf

2lf, ,<,2fst
2lf,0,<,2lf
2lf,1,<,2lf
2lf,2,<,2lf
2lf,3,<,2lf
2lf,4,<,2lf
2lf,5,<,2lf
2lf,6,<,2lf
2lf,7,<,2lf

3lf, ,<,3fst
3lf,0,<,3lf
3lf,1,<,3lf
3lf,2,<,3lf
3lf,3,<,3lf
3lf,4,<,3lf
3lf,5,<,3lf
3lf,6,<,3lf
3lf,7,<,3lf

4lf, ,<,4fst
4lf,0,<,4lf
4lf,1,<,4lf
4lf,2,<,4lf
4lf,3,<,4lf
4lf,4,<,4lf
4lf,5,<,4lf
4lf,6,<,4lf
4lf,7,<,4lf

5lf, ,<,5fst
5lf,0,<,5lf
5lf,1,<,5lf
5lf,2,<,5lf
5lf,3,<,5lf
5lf,4,<,5lf
5lf,5,<,5lf
5lf,6,<,5lf
5lf,7,<,5lf

6lf, ,<,6fst
6lf,0,<,6lf
6lf,1,<,6lf
6lf,2,<,6lf
6lf,3,<,6lf
6lf,4,<,6lf
6lf,5,<,6lf
6lf,6,<,6lf
6lf,7,<,6lf

7lf, ,<,7fst
7lf,0,<,7lf
7lf,1,<,7lf
7lf,2,<,7lf
7lf,3,<,7lf
7lf,4,<,7lf
7lf,5,<,7lf
7lf,6,<,7lf
7lf,7,<,7lf

// возвращаем затертую цифру в первоначальном числе

0fst, ,0,r2
0fst,0,<,0fst
0fst,1,<,0fst
0fst,2,<,0fst
0fst,3,<,0fst
0fst,4,<,0fst
0fst,5,<,0fst
0fst,6,<,0fst
0fst,7,<,0fst

1fst, ,1,r2
1fst,0,<,1fst
1fst,1,<,1fst
1fst,2,<,1fst
1fst,3,<,1fst
1fst,4,<,1fst
1fst,5,<,1fst
1fst,6,<,1fst
1fst,7,<,1fst

2fst, ,2,r2
2fst,0,<,2fst
2fst,1,<,2fst
2fst,2,<,2fst
2fst,3,<,2fst
2fst,4,<,2fst
2fst,5,<,2fst
2fst,6,<,2fst
2fst,7,<,2fst

3fst, ,3,r2
3fst,0,<,3fst
3fst,1,<,3fst
3fst,2,<,3fst
3fst,3,<,3fst
3fst,4,<,3fst
3fst,5,<,3fst
3fst,6,<,3fst
3fst,7,<,3fst

4fst, ,4,r2
4fst,0,<,4fst
4fst,1,<,4fst
4fst,2,<,4fst
4fst,3,<,4fst
4fst,4,<,4fst
4fst,5,<,4fst
4fst,6,<,4fst
4fst,7,<,4fst

5fst, ,5,r2
5fst,0,<,5fst
5fst,1,<,5fst
5fst,2,<,5fst
5fst,3,<,5fst
5fst,4,<,5fst
5fst,5,<,5fst
5fst,6,<,5fst
5fst,7,<,5fst

6fst, ,6,r2
6fst,0,<,6fst
6fst,1,<,6fst
6fst,2,<,6fst
6fst,3,<,6fst
6fst,4,<,6fst
6fst,5,<,6fst
6fst,6,<,6fst
6fst,7,<,6fst

7fst, ,7,r2
7fst,0,<,7fst
7fst,1,<,7fst
7fst,2,<,7fst
7fst,3,<,7fst
7fst,4,<,7fst
7fst,5,<,7fst
7fst,6,<,7fst
7fst,7,<,7fst

// после печати цифры, переходим на 1 элемент вправо

r2,0,>,02
r2,1,>,02
r2,2,>,02
r2,3,>,02
r2,4,>,02
r2,5,>,02
r2,6,>,02
r2,7,>,02
