function out = edge_based_seg(inp)

%inp = ordfilt2(inp, 15*15, ones(15,15));
%inp = basic_global_threshold(inp, 0);
se = strel('diamond', 1);
inp_eroded = imerode(inp, se);
out = inp - inp_eroded;

%out = imclose(out, se);
% se = strel('ball', 2, 1);
% inp_eroded = imerode(inp, se);
% out = inp - inp_eroded;


imshow(out);
imwrite(out, 'edge_based_seg.png');

end