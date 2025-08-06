/*
Na main:
declara i = 3
declara *a = &i
chama fa(a)

primeira chamada: fa33(a)
c = a   // c = 3
c > 0, c = c-1   //c = 2
chama fa15(c)

Segunda chamada: fa15(c)
c = c   // c = 2
c > 0, c = c-1   //c = 1
chama fa15(c)

Terceira chamada: fa15(c)
c = c   // c = 1
c > 0, c = c-1   //c = 0
chama fa(c)

Quarta chamada: fa15(c)
c = c   // c = 0
c = 0, PARA!

volta para a terceira chamada
c = c - 1   // c = -1
chama fa(c)

quinta chamada: fa17(c)
c = c   // c = -1
c<0, PARA!

volta para a terceira chamada
d = c   //d = -1
d % 2 != 0 
chama fb20(d)

sexta chamada fb20(d)
d = d +1   // d = 0
a < 1, Para!!

volta para a terceira chamada
printa d = 0
d = d - 1   // d = -1
chama fa24(d)

sétima chamada fa24(d)
c = d   // c = -1
c < 0, PARA!

volta para a terceira chamada
printa c = -1
printa b = -1
Para!

volta para a segunda chamada
c = c-1 = c = 0
chama fa17(c)

oitava chamada
















*/