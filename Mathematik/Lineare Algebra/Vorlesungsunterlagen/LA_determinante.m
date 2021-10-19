function [det] = determinante ( A )
% Berchnung der Determinante mit Rekursionsformel
% Pruefung
[n,m] = size(A);  %% Anzahl der Zeilen und Spalten

if n==1
    %% Rekursion endet hier ...
    det=A(1,1);
elseif n==2
    %% ... oder fuer n = 2 
    det=A(1,1)*A(2,2)-A(2,1)*A(1,2);
elseif n > 2
    det=0;
    for i = 1:n
        %% A kopieren, da A selbst noch gebraucht wird
        Q = A;
        Q(:,i) = [];                    %% Streichung i-te Spalte
        Q(1,:) = [];                    %% Streichung erste Zeile
        det = det + (-1)^(i+1) * A(1,i) * determinante(Q);  %% Entwicklung
    end
end