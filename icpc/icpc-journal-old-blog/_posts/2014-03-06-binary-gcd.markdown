---
layout: post
title:  "Binary GCD"
date:   2014-03-06 00:30:00
comments: true
tags: math
---

# Código

{% highlight c++ %}
int binary_gcd(int a, int b) {
  if (a == b)
    return a;
  if (!a)                       // a == 0
    return b;
  if (!b)                       // b == 0
    return a;

  if (~a & 1) {                 // a par
    if (~b & 1)                 // b par
      return binary_gcd(a >> 1, b >> 1) << 1;
    else                        // b ímpar;
      return binary_gcd(a >> 1, b);
  }
  else {                        // a ímpar
    if (~b & 1)                 // b par
      return binary_gcd(a, b >> 1);
    else {                      // b ímpar
      if (a > b)
        return binary_gcd( (a - b) >> 1, b);
      else
        return binary_gcd( (b - a) >> 1, a);
    }
  }
}
{% endhighlight %}

# Testes
* [binary_gcd.cpp]({{ site.baseurl }}{{ site.code }}/binary_gcd.cpp)
* [gcd.in]({{ site.baseurl }}{{ site.code }}/gcd.in)
* [gcd.out]({{ site.baseurl }}{{ site.code }}/gcd.out)

# Complexidade
* Igual a do gcd convencional.

# Comentários
* Uma forma alternativa de calcular o gcd, utilizando operações bit-a-bit.
* Tende a ser mais eficiente para números grandes.

# See also
+ [https://en.wikipedia.org/wiki/Binary_GCD_algorithm](https://en.wikipedia.org/wiki/Binary_GCD_algorithm)
