function m = gaussian_filterWithPadding(x)

filterSize = 3;
filterFactor = filterSize - 1;

[row, column] = size(x);
newRow = row + 2 * filterFactor;
newColumn = column + 2 * filterFactor;
m = zeros(newRow, newColumn);
filter = [1 2 1; 2 4 2; 1 2 1];

for r = 1 : row
    for c = 1 : column
        rowM = r + filterFactor;
        columnM = c + filterFactor;
        m(rowM, columnM) = x(r, c);
    end
end

for r = 2 : newRow - 1
    for c = 2 : newColumn - 1
        prod = m(r - 1: r + 1, c - 1: c + 1) .* filter;
        m(r,c) = sum(sum(prod) / sum(sum(filter)));
    end
end

m = uint8(m);
m = m(1 + filterFactor : newRow - filterFactor, 1 + filterFactor : newColumn - filterFactor);
end