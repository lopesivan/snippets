---
layout: post
title:  "Insertion Sort"
date:   2014-03-06 23:19:00
comments: true
tags: sorting
---

# Código

{% highlight c++ %}
void insertion_sort(int *v, int n) {
  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j > 0; --j) {
      if (v[j] < v[j-1])
        swap(v[j], v[j-1]);
      else
        break;
    }
  }
}
{% endhighlight %}

# Testes
* [insertion_sort.cpp]({{ site.baseurl }}{{ site.code }}/insertion_sort.cpp)
* [sort.in]({{ site.baseurl }}{{ site.code }}/sort.in)
* [sort.out]({{ site.baseurl }}{{ site.code }}/sort.out)

# Aplicações
+ Contar o número de inversões. Basta incrementar um contador sempre que uma troca for feita.

# Complexidade
+ n = número de elementos
+ Temporal (pior caso): O(n²)
+ Temporal (caso médio): proporcional à desordenação do vetor
+ Temporal (melhor caso): O(n)

# Comentários
+ Inverter a ordenação;
+ Menores elementos primeiro / maiores elementos primeiro
* Troca apenas elementos adjacentes.
* Estável (não troca elementos iguais).

# See also
+ [http://www.sorting-algorithms.com/](http://www.sorting-algorithms.com/)
