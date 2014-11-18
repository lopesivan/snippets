clear all

m = sym('m',[1 2]);
xprevglob = sym('xprevglob', [1 2]);
a = [2.0 1.0; 1.0 1.0; -1.0 0.0; 0.0 -1.0];
b = [6.0; 4.0; 0.0; 0.0];

f = -sqrt(m(1) * m(2));
grad_f = gradient(f, [m(1) m(2)]);
inv_hess_f = inv(hessian(f, [m(1) m(2)]));

d = 0.0;
for i = 1:4   
    d = d + ((b(i) - a(i,:) * m.') * log((b(i) - a(i,:) * m.') / (b(i) - a(i,:) * xprevglob.'))) + (a(i,:) * (m.' - xprevglob.'));
end
grad_d = gradient(d, [m(1) m(2)]);
inv_hess_d = inv(hessian(d, [m(1) m(2)]));

g = f + d;
grad_g = gradient(g, [m(1) m(2)]);
inv_hess_g = inv(hessian(g, [m(1) m(2)]));

syms kglob;
g2 = f + kglob * d;
grad_g2 = gradient(g2, [m(1) m(2)]);
inv_hess_g2 = inv(hessian(g, [m(1) m(2)]));