---
layout: post
title:  "Merge Sort"
date:   2014-03-06 19:47:00
comments: true
tags: sorting
---

# Código

{% highlight c++ %}
void merge_sort(int *v, int a, int b) {

int middle = a + (b - a) / 2;

  if ( a != middle ) {
    merge_sort(v, a, middle);
    merge_sort(v, middle + 1, b);
  }

  int n = b - a + 1;
  int *aux = new int[n];

  int i1 = a; // <= middle
  int i2 = middle + 1; // <= b
  
  for (int i = 0; i < n; ++i) {
    
    if (i1 > middle) {
      aux[i] = v[i2++];
      continue;
    }

    if (i2 > b) {
      aux[i] = v[i1++];
      continue;
    }

    if (v[i1] < v[i2])
      aux[i] = v[i1++];

    else
      aux[i] = v[i2++];
  }

  for (int i = 0; i < n; ++i)
    v[a + i] = aux[i];
}
{% endhighlight %}

# Testes

* [merge_sort.cpp]({{ site.baseurl }}{{ site.code }}/merge_sort.cpp)
* [sort.in]({{ site.baseurl }}{{ site.code }}/sort.in)
* [sort.out]({{ site.baseurl }}{{ site.code }}/sort.out)

# Complexidade
* Temporal (pior caso, caso médio, melhor caso): `O(n * log n)`
* Espacial: `O(n)` (2n). Precisa de um vetor auxiliar, pois a versão *in place* é mais complicada.


# Comentários

* Primeira constatação: ordenar o intervalo `[a,b]` é o mesmo que ordenar os 2 subintervalos `[a,meio]` e `[meio+1,b]`, e depois juntá-los ("dar merge" neles).
* A ordenação dos subintervalos é feita de modo recursivo. 2 cuidados aqui:
    * 1. assegurar-se de que está dividindo o intervalo corretamente. Por exemplo, **não** divida `{1,2,3,4}` como `{1,2,3}` e `{4}`.
    * 2. critério de parada! Você não irá querer chamar as funções -- infinitamente -- para intervalos de tamanho 1 ou 2.
* Para *dar merge*: não fazer nada **in place**. Copiar tudo para um vetor temporário. Global ou não, dinâmico ou não, você quem sabe. O cuidado principal aqui é o de manter dois ponteiros (um percorrendo cada subintervalo) e checar quando cada um deles terminou de percorrer o que devia.
* Há quem crie duas funções: `merge_sort` e `merge`. Porém isso não é absolutamente necessário.
* Eu acho que a velocidade com que você consegue *codar* essa função, **sem errar**, é um ótimo indicativo do quanto você está ativo. Sério. É muito fácil cometer um errinho ou outro (do critério de parada, do intervalo de cada chamada, da cópia do vetor), são vários detalhezinhos. Apesar disso, essa é uma das funções mais bonitas no que diz respeito à recursão. A implementação em Lisp (uma linguagem funcional) é mais bonita ainda.
* Você deve tomar uma decisão cedo: vai considerar o intervalo da forma `[a,b]`, ou da forma ```[a,b)```? Esse é um dos detalhes que dão nó na cabeça.
* GDB é um ótimo amigo aqui. Bom, o printf ainda é seu amigo mas, especialmente, o GDB é ótimo nesse caso para detectar o que deu errado.

# See also
+ [http://www.sorting-algorithms.com/](http://www.sorting-algorithms.com/)
