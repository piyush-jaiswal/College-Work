img = imread('head.png');
img = rgb2gray(img);

noisy_img = imnoise(inp, 'salt & pepper', 0.05);
imshow(noisy_img);
imwrite(noisy_img, 'noisy image.png');

filtered_img = medfilt2(noisy);
figure, imshow(filtered_img);
imwrite(filtered_img, 'filtered image.png');