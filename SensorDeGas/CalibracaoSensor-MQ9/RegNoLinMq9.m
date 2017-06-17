function [fitresult, gof] = RegNoLinMq9(x, yn)
%Criando fun��o para ajuste de curva, usando m�todo dos m�nimos quadrados
%generalizado


%% Dados da curva
[xData, yData] = prepareCurveData( x, yn );

% Op��es de para plotar a curva baseada nas condi��es que os dados
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


