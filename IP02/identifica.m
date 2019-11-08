x(:,2)=output_real.signals.values;
x(:,1)=output_real.time;
 
%Parametros pico e tp
[xm,im]=max(x(:,2));
tp=x(im,1);
xf=mean(x(end-100:end,2));
 
%Parametros MP,ksi e wn
Mp=(xm - xf)/xf;
qsi=log(1/MP)/sqrt(pi^2 + (log(1/MP))^2);
wn=pi/(tp*sqrt(1-qsi^2));

amp_step=0.001;
K=xf*wn^2/amp_step;

 
%Parametros a e b
a=2*qsi*wn;
b=wn^2 /420;
 
%FT em MA
g=tf(b,[1 a 0]);
%FT em MF
gs=tf(b,[1 a b]);
 
%plot(x(:,1),x(:,2));
%plot (gs);
%plot (g);


%% controlador

Ts = 0.1;

g = tf([b], [1 a 0 0], Ts);

margin(g);








