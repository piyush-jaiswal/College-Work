f = rgb2gray(imread('Gray-Wolves-Desktop-Wallpaper.jpg'));
h = imhist(f,50);
horz = linspace(0,255,50);
bar(horz,h)
axis([0 255 0 768*1366])
set(gca, 'xtick', 0:50:255)
set(gca, 'ytick', 0:15000:768*1366)