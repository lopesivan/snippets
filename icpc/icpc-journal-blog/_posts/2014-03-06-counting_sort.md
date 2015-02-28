---
layout: post
title:  "Counting Sort"
date:   2014-03-06 20:35:00
comments: true
tags: sorting
---

# Código

{% highlight c++ %}
void counting_sort(int *v, int n) {
  int maior = INT_MIN;

  for (int i = 0; i < n; ++i)
    maior = max(maior, v[i]);

  int *count = new int[maior + 1]; // please do not overflow...
  memset(count, 0, (maior + 1) * sizeof(int));

  for (int i = 0; i < n; ++i)
    ++count[ v[i] ];

  int qt = 0;
  for (int i = 0; i <= maior && qt < n; ++i) {
    if (count[i] > 0) {
      for (int k = 0; k < count[i]; ++k)
        v[qt++] = i;
    }
  }
}
{% endhighlight %}

# Testes
* [counting_sort.cpp]({{ site.baseurl }}{{ site.code }}/counting_sort.cpp)
* [sort.in]({{ site.baseurl }}{{ site.code }}/sort.in)
* [sort.out]({{ site.baseurl }}{{ site.code }}/sort.out)

# Aplicações
* Funciona apenas para números inteiros não-negativos, e pequenos. Não pode ser muito grande porque você precisa de um vetor com tamanho igual ao maior elemento do seu conjunto.

# Complexidade
+ n = número de elementos
+ Temporal : `O(n)`. Melhor, impossível.

# Comentários
* Easy-peasy. Ainda mais fácil do que o selection sort.
* Atenção para não imprimir espaço em branco no final.
* Na prática, a versão *in place* não é tão usada; manipula-se mais o vetor *count* mesmo.

# See also
+ Problema super, super clássico: [UVa 11462](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2457)
