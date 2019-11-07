function [qsi wn K] = estima_sys_2ordem(Tp,ymax,yfinal,amp_step)

SP=((ymax-yfinal)/yfinal)*100;
qsi=-log(SP/100)/sqrt(pi^2+log(SP/100)^2);
wn=pi/(Tp*sqrt(1-qsi^2));
K=yfinal*wn^2/amp_step;