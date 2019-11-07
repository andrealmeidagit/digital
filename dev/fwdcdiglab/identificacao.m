x(:,2)=output_real.signals.values;
x(:,1)=output_real.time;

%Parametros pico e tp
[pico,pos_pico]=max(x(:,2));
tp=x(pos_pico,1);
y_final=x(end,2);

%Parametros MP,ksi e wn
MP=(pico-y_final)/y_final;
ksi=log(1/MP)/sqrt(pi^2 + (log(1/MP))^2);
wn=pi/(tp*sqrt(1-ksi^2));

%Parametros a e b
a=2*ksi*wn;
b=wn^2;

%FT em MA
g=tf(b,[1 a 0]);
%FT em MF
gs=tf(b,[1 a b]);

%plot(x(:,1),x(:,2));
%plot (gs);
%plot (g);

