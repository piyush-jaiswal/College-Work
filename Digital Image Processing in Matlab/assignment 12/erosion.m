function out = erosion(img)

if ~isa(img, 'logical')
    img = imbinarize(img);
end

seSize = 3;
paddingFactor = floor(seSize / 2);
se = [0 1 0; 1 1 1; 0 1 0];

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
        temp = imgPadded(r - paddingFactor : r + paddingFactor, c - paddingFactor: c + paddingFactor);
        if isequal(temp & se, se)
            out(r - paddingFactor, c - paddingFactor) = 255;
        else
            out(r - paddingFactor, c - paddingFactor) = 0;
        end
    end
end

out = imbinarize(out);
end