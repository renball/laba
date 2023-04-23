close all;
clc;
clear;

FontSize = 10;
filename1 = '/users/q/source/repos/D_O/results.txt';
filename2 = '/users/q/source/repos/D_O/results2.txt';
filename3 = '/users/q/source/repos/D_O/results2_2.txt';
filename4 = '/users/q/source/repos/D_O/results3.txt';

Data = importdata( [ filename1 ] );
time1   = Data(:, 1);
V1   = Data(:, 2);

Data = importdata( [ filename2 ] );
xn   = Data(:, 1);
xnn   = Data(:, 2);

Data = importdata( [ filename3 ] );
xnl   = Data(:, 1);
xnnl   = Data(:, 2);

Data = importdata( [ filename4 ] );
r   = Data(:, 1);
A   = Data(:, 2);

fig_Ca_IP3_z = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
%scatter(time1, V1, 'r', 'LineWidth', 0.01);
%plot(xn,xnn,xnl,xnnl,'r', 'LineWidth', 0.01);
plot(r,A,'r', 'LineWidth', 0.01);
hold on;
grid on;
