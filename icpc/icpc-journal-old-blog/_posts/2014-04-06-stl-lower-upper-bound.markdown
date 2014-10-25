---
layout: post
title:  "STL Lower and Upper Bound"
date:   2014-04-06 22:54:00
comments: true
tags: stl
---

# Código

{% highlight c++ %}
upper_bound(v, v + n, value);
upper_bound(v.begin(), v.end(), value);
upper_bound(v.begin(), v.end(), value, pred_sort);

lower_bound(v, v + n, value);
lower_bound(v.begin(), v.end(), value);
lower_bound(v.begin(), v.end(), value, pred_sort);
{% endhighlight %}


# Comentários
+ `upper_bound`: pesquisa binária num container. Retorna um iterador para o primeiro elemento **maior** que o especificado.
+ `lower_bound`: pesquisa binária num container. Retorna um iterador para o primeiro elemento **maior ou igual** (= não-menor) que o especificado.
+ Note que para obter a posição (índice, inteiro não-negativo) do container podemos subtrair v.begin() dessas funções.
+ Também não há problemas subtrair uma função da outra. Utilize esse fato para encontrar a quantidade de elementos que você quer.
