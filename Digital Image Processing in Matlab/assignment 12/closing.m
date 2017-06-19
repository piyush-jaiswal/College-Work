function out = closing(img)

out = erosion(dilation(img));

end