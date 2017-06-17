function [fitresult, gof] = RegNoLinMq9(x, yn)
%Criando função para ajuste de curva, usando método dos mínimos quadrados
%generalizado


%% Dados da curva
[xData, yData] = prepareCurveData( x, yn );

% Opções de para plotar a curva baseada nas condições que os dados
% apresentam
ft = fittype( 'power1' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';


% Modelo de Ajuste.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plotando
figure( 'Name', 'Curva de Ajuste MQ9-CO' );
h = plot( fitresult, xData, yData );
legend( h, 'y vs. x', 'Curva de Ajuste MQ9-CO', 'Location', 'NorthEast' );
% Eixos
xlabel ppm
ylabel Rs/R0
grid on


