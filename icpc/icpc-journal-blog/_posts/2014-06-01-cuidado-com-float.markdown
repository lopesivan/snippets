---
layout: post
title:  "Cuidado com floats!"
date:   2014-06-01 01:30:00
comments: true
tags: cpp
---

# Código

Cuidado ao utilizar *float* em *programming contests*! É preferível utilizar *double*, a menos que você vá alocar elementos demais.

No [seguinte problema](http://codeforces.com/contest/1/problem/A) do Codeforces, o seguinte código falha no caso 15:

{% highlight c++ %}
int main() {
  int n, m, a;
  scanf("%d%d%d", &n, &m, &a);

  int ans  = ceil(float(n)/a) * ceil(float(m)/a);
  printf("%d\n", ans);
  
  return 0;
}
{% endhighlight %}

Esse falha no caso 16:

{% highlight c++ %}
int main() {
  int n, m, a;
  scanf("%d%d%d", &n, &m, &a);

  int  = ceil(double(n)/a) * ceil(double(m)/a);
  printf("%d\n", ans);
  
  return 0;
}
{% endhighlight %}


E esse finalmente passa:

{% highlight c++ %}
int main() {
  int n, m, a;
  scanf("%d%d%d", &n, &m, &a);

  long long ans  = ceil(double(n)/a) * ceil(double(m)/a);
  printf("%I64d\n", ans);
  
  return 0;
}
{% endhighlight %}


A diferença entre o segundo e o terceiro é mais uma questão de observar os limites do problema; agora, bastante cuidado com a diferença do primeiro para o segundo! Bits são finitos, assim como a precisão de ponto flutuante do seu processador.
