---
layout: post
title:  "Inteiros de precisão arbitrária em C++"
date:   2014-04-22 12:28:00
comments: true
tags: libraries blog
---

Recentemente um amigo propôs o [seguinte](https://www.facebook.com/groups/osadpa/permalink/505987316173467/?stream_ref=2) desafio em um grupo do Facebook:

<blockquote>
[DESAFIO / LANGUAGE WAR] Implemente um programa na sua linguagem favorita onde o usuário digita um número x, e o programa calcula o somatório dos x primeiros números pares da sequência fibonacci, e imprime a soma dos algarismos desse número.
Por exemplo, quando x = 5, a resposta é 17, pois:
1. A sequência fibonacci é 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,...
2. Os 5 primeiros números pares são 0, 2, 8 e 34, 144.
3. O somatório disso é 188.
4. Somando os algarismos, 1+8+8 = 17
Rode o programa para o caso X = 100000 usando o comando `echo 100000 | time ./programa`. Confira se a resposta é 282042 e poste aqui o código fonte e o tempo de execução. Ganha a linguagem que tiver o código mais elegante e rápido.
</blockquote>

Ele resolveu esse problema em [Haskell](http://haskell.org) de forma bastante elegante:

{% highlight haskell %}
fibonacci = scanl (+) 0 (1:fibonacci)
sum_digits = sum . map (read . return) . show
main = readLn >>= (\x -> print $ sum_digits $ sum $ take x $ filter even $ fibonacci)
{% endhighlight %}

Eis os resultados de execução:

```
Tempo de execução: 5.21 segundos

$ echo 100000 | time ./programa
282042
5.31 real 4.07 user 1.20 sys
```

O que não é nada mal! O que impressiona mais nisso tudo, é claro, é o poder de expressão que o programador tem com uma linguagem funcional. Imagino que deva ser ótima a sensação de dominar uma delas. Pessoalmente, com a pouca [experiência][1] que tenho com Emacs Lisp, já consigo configurar o meu editor de modo confortável. Agora, imagina se também pudesse manipular números, fórmulas e até servidores com algumas funções de uma linguagem funcional...er, um dia, um dia.

Pois que resolvi realizar essa implementação em C++. O primeiro "desafio" já foi mais desmotivador do que o desafio original: em um inteiro de 64 bits o maior número de Fibonacci que podemos incluir está em torno do 170º. Aí você diz: ah, vamos utilizar python, é baseado em C e tem inteiros de precisão arbitrária (carinhosamente: **big ints**) *out-of-the-box*. É, pode ser, mas a proposta do desafio era realizar uma implementação rápida, e eu tenho certeza que C ou C++ são mais rápidos em tempo de execução, no caso geral, do que Python. Sem contar que eu pessoalmente tenho mais experiência com C++ do que com Python (apesar da simplicidade da sintaxe de Python).

Então, fui procurar uma biblioteca de bigint para C++. Sabia que tinha uma. Até porque o Python é baseado em C..OK, encontrei [essa][2]. Problema: coisa de Microsoft Visual Studio. Mesmo com um pouco de esforço, o g++ estava reclamando com vários warnings...daí você vê: não é absolutamente portável.

Segunda tentativa: encontrei a [GMP][gmplib] ([Wiki][wikigmp]). Biblioteca da GNU, livre, bonitinha, universo e tudo o mais. Percebi que essa biblioteca inclusive já estava instalada no meu Arch. Vários pacotes importantes dependem dela:

```
:: coreutils: requires gmp
:: dnsmasq: requires gmp
:: guile: requires gmp
:: guile1.8: requires gmp
:: isl: requires gmp
:: mpfr: requires gmp>=5.0
:: nettle: requires gmp
:: ruby: requires gmp
```

Eis os seus arquivos:

```
gmp /usr/
gmp /usr/include/
gmp /usr/include/gmp.h
gmp /usr/include/gmpxx.h
gmp /usr/lib/
gmp /usr/lib/libgmp.so
gmp /usr/lib/libgmp.so.10
gmp /usr/lib/libgmp.so.10.2.0
gmp /usr/lib/libgmpxx.so
gmp /usr/lib/libgmpxx.so.4
gmp /usr/lib/libgmpxx.so.4.4.0
gmp /usr/share/
gmp /usr/share/info/
gmp /usr/share/info/gmp.info-1.gz
gmp /usr/share/info/gmp.info-2.gz
gmp /usr/share/info/gmp.info.gz
```

Se eu consegui listar essas duas coisas acima tão facilmente, agradeça ao [pacman][pacman]. E, se não funcionar, a culpa é do [Allan][mcrae], falo logo.

Back *on topic*: depois de aprender a mexer com o basicão da GMP, implementei [esse][codigo] código. Resultados:

```
thiago@arch ~/inbox $ echo 100000 | time ./fibo-challenge
282042
./fibo-challenge 1.01s user 0.75s system 99% cpu 1.771 total
```

**Conclusão 1:** C++ é mais rápido que haskell. **3x mais nesse caso**. Você pode argumentar que eu compilei com -O3 e que a versão do código em Haskell não está otimizada, mas eu duvido que uma versão otimizada melhore muito. De qualquer forma, se você programar numa linguagem funcional, você não vai (em geral) ficar perdendo tempo otimizando ou escrevendo para a melhor execução possível: você vai é aproveitar as facilidades que a linguagem te oferece, as funções e bibliotecas dela, para escrever rápido.

**Conclusão 2:** a sintaxe nem é tão difícil, não é? Você tem que ficar chamando as funções da GMP para tudo, o que é relativamente chato, mas funciona, e nem é algo tão absurdo (acredite, poderia ser pior).

Fato triste: infelizmente, a probabilidade de eu poder utilizar uma coisa dessas na maratona (ICPC) é mínima. Mesmo que pudesse, não haveria internet, então todas as funções que eu fosse pensar em utilizar deveriam estar nas minhas referências. O que é **cumbersome**, sorry. Para Big Int na maratona, há táticas melhores (<strike>ignorar o problema</strike>).


[gmplib]: https://gmplib.org/
[wikigmp]: https://en.wikipedia.org/wiki/GNU_Multi-Precision_Library
[1]: https://github.com/thiagowfx/dotfiles/blob/master/.emacs
[2]: http://www.hvks.com/Numerical/arbitrary_precision.html
[codigo]: https://gist.github.com/thiagowfx/11169350
[pacman]: https://wiki.archlinux.org/index.php/Pacman
[mcrae]: http://allanmcrae.com/
