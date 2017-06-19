function out = opening(img)

out = dilation(erosion(img));

end