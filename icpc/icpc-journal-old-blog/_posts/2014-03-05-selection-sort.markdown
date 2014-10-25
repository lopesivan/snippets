---
layout: post
title:  "Selection Sort"
date:   2014-03-05 21:33:00
comments: true
tags: sorting
---

# Código

{% highlight c++ %}
void selection_sort(int *v, int n) {
  int imenor;

  for (int i = 0; i < n;  ++i) {

    int menor = INT_MAX;

    for (int j = i; j < n; ++j) {
      if (v[j] < menor) {
        imenor = j;
        menor = v[j];
      }
    }
    swap( v[i], v[imenor] );
  }
}
{% endhighlight %}

# Testes

* [selection_sort.cpp]({{ site.baseurl }}{{ site.code }}/selection_sort.cpp)
* [sort.in]({{ site.baseurl }}{{ site.code }}/sort.in)
* [sort.out]({{ site.baseurl }}{{ site.code }}/sort.out)

# Complexidade
+ n = número de elementos
+ Temporal (pior caso, caso médio, melhor caso): O(n²)

# Comentários
+ Inverter a ordenação;
+ Menores elementos primeiro / maiores elementos primeiro
+ O algoritmo de ordenação mais fácil de entender.
+ Estilo cartas de baralho.
+ No máximo n trocas são feitas. Em geral, não são adjacentes.
+ Estável (não troca elementos iguais).

# See also
+ [http://www.sorting-algorithms.com/](http://www.sorting-algorithms.com/)
