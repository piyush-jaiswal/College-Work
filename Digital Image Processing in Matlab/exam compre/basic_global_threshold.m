function out = basic_global_threshold(inp, tolerance)

maxValue = 255;
currentThresh = findMean(inp, maxValue);
newThresh = findMean(inp, currentThresh);

while abs(newThresh - currentThresh) > tolerance * currentThresh
    currentThresh = newThresh;
    newThresh = findMean(inp, currentThresh);
end
globalThresh = newThresh;

[row, column] = size(inp);
out = zeros(row, column);
for r = 1 : row
    for c = 1 : column
        if inp(r, c) > globalThresh
            out(r, c) = 255;
        end
    end
end

% out = imbinarize(out);
imshow(out);
imwrite(out, 'basic_global_threshold.png');

end