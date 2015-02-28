---
layout: post
title:  "Bubble Sort"
date:   2014-03-04 20:37:00
comments: true
tags: sorting
---

# Código

{% highlight c++ %}
void bubble_sort(int *v, int n) {
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[j + 1])
        swap( v[j], v[j+1] );
    }
  }
}
{% endhighlight %}

# Otimizado

{% highlight c++ %}
void bubble_sort(int *v, int n) {
  for (int i = n - 1; i >= 0; --i) {
    bool swapped = false;
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[j + 1]) {
        swap( v[j], v[j+1] );
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}
{% endhighlight %}


# Testes
* [bubble_sort.cpp]({{ site.baseurl }}{{ site.code }}/bubble_sort.cpp)
* [sort.in]({{ site.baseurl }}{{ site.code }}/sort.in)
* [sort.out]({{ site.baseurl }}{{ site.code }}/sort.out)


# Aplicações
+ Contar o número de inversões. Basta incrementar um contador sempre que uma troca for feita.


# Complexidade
+ n = número de elementos
+ Temporal (pior caso, caso médio): O(n²);
+ Temporal (melhor caso): O(n)

# Comentários
+ Inverter a ordenação;
+ Menores elementos primeiro / maiores elementos primeiro
* Troca apenas elementos adjacentes.
* Muitas trocas podem ser realizadas (cuidado!)
* Estável (não troca elementos iguais).

# See also
* [http://www.sorting-algorithms.com/](http://www.sorting-algorithms.com/)
