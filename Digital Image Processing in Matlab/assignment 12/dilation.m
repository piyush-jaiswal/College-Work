function out = dilation(img)

if ~isa(img, 'logical')
    img = imbinarize(img);
end

seSize = 3;
se = [0 1 0; 1 1 1; 0 1 0];
paddingFactor = floor(seSize / 2);

[row, column] = size(img);
newRow = row + 2 * paddingFactor;
newColumn = column + 2 * paddingFactor;

imgPadded = zeros(newRow, newColumn);
for r = 1 : row
    for c = 1 : column
        imgPadded(r + paddingFactor, c + paddingFactor) = img(r, c);
    end
end
imgPadded = imbinarize(imgPadded);

out = zeros(row, column);
for r = 2 : newRow - paddingFactor
    for c = 2 : newColumn - paddingFactor
        temp = imgPadded(r - paddingFactor : r + paddingFactor, c - paddingFactor : c + paddingFactor);
        out(r - paddingFactor, c - paddingFactor) = max(max(temp & se)) * 255;
    end
end
out = imbinarize(out);

end