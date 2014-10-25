---
layout: post
title:  "Binary Search"
date:   2014-03-07 00:29:00
comments: true
tags: searching
---

# Código

{% highlight c++ %}
int binary_search(int *v, int a, int b, int key) {

  int middle = a + (b - a) / 2;

  if (v[middle] == key) {
    // return middle;
    while( middle >= 0 && v[middle] == key )
      --middle;
    return middle + 1;
  }
  
  else if (middle == a)
    return -1;
           
  else if (v[middle] > key)
    return binary_search(v, a, middle, key);
  
  else if (v[middle] < key)
    return binary_search(v, middle + 1, b, key);
  
  else
    return -2; // shouldn't happen!
}
{% endhighlight %}

# Testes

* [binary_search.cpp]({{ site.baseurl }}{{ site.code }}/binary_search.cpp)
* [binary_search.in]({{ site.baseurl }}{{ site.code }}/binary_search.in)
* [binary_search.out]({{ site.baseurl }}{{ site.code }}/binary_search.out)

# Complexidade
+ Temporal: O(log n). Divide um intervalo em 2 a cada etapa.

# Comentários
* Cuidado com a sua convenção: `[a,b]` ou `[a,b)`?
* Cuidado para se assegurar de que o vetor esteja ordenado.
* Essa pesquisa binária convencional já existe na biblioteca padrão do C, `bsearch`. Veja em [1]. Uso típico: `pItem = (int*) bsearch (&key, values, 6, sizeof (int), compareints);` (se parece com a do qsort). Retorna um ponteiro para o elemento encontrado. O problema dessa função é que ela é básica demais: você não pode personalizá-la.

[1]: http://www.cplusplus.com/reference/cstdlib/bsearch/
