---
layout: post
title:  "Snail sort and STL next permutation"
date:   2014-03-07 23:25:00
comments: true
tags: sorting codejam blog
---

# Código

{% highlight c++ %}
void snail_sort(char *input) {
  int tam = strlen(input);
  while( next_permutation(input, input + tam) );
}
{% endhighlight %}


# Testes
* [snail_sort_next_permutation.cpp]({{ site.baseurl }}{{ site.code }}/snail_sort_next_permutation.cpp)
* [snail_sort_next_permutation.in]({{ site.baseurl }}{{ site.code }}/snail_sort_next_permutation.in)
* [snail_sort_next_permutation.out]({{ site.baseurl }}{{ site.code }}/snail_sort_next_permutation.out)

# Comentários
Snail sort é um algoritmo de ordenação que fica permutando os elementos até que o todo fique ordenado. Você pode fazer essa permutação [de modo caótico](http://faculty.valpo.edu/jcaristi/vegas.pdf), ou pode ficar permutando os elementos sequencialmente, como no exemplo. O último caso, ao menos, tem um fim garantido (com complexidade `O(n!)`<sup>[1]</sup>).

A função *next_permutation* da STL é bastante simpática, e retorna falso quando damos "wrap" da última permutação para a primeira (em relação à ordem lexicográfica das permutações).

Eis a versão genérica (em termos de classes) do código:


{% highlight c++ %}
template<typename T>
void snail_sort_generic(T begin, T end) {
  while (next_permutation(begin, end) );
}
{% endhighlight %}


# See also
* [Cornell CS1114 Assignment](http://www.cs.cornell.edu/courses/CS1114/2012sp/assignments/A2.pdf)
* [Word Aligned's GCJ Discussion](http://wordaligned.org/articles/next-permutation)


<sup>[1]</sup> Supondo que next_permutation seja `O(1)`, o que não é completamente verdadeiro.
