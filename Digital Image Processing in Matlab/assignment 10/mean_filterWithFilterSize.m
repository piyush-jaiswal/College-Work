function m = mean_filterWithFilterSize(x, filterSize)

filterFactor = filterSize - 1;

[row, column] = size(x);
newRow = row + 2 * filterFactor;
newColumn = column + 2 * filterFactor;
m = zeros(newRow, newColumn);
filter = ones(filterSize);

% copy the value from original to the padded one
for r = 1 : row
    for c = 1 : column
        rowM = r + filterFactor;
        columnM = c + filterFactor;
        m(rowM, columnM) = x(r, c);
    end
end

% perform filtering
filterFactorOneSide = floor(filterFactor / 2);
for r = filterFactorOneSide + 1 : newRow - filterFactorOneSide
    for c = filterFactorOneSide + 1 : newColumn - filterFactorOneSide
        prod = m(r - filterFactorOneSide: r + filterFactorOneSide, c - filterFactorOneSide: c + filterFactorOneSide) .* filter;
        m(r,c) = sum(sum(prod) / sum(sum(filter)));
    end
end

m = uint8(m);
m = m(1 + filterFactor : newRow - filterFactor, 1 + filterFactor : newColumn - filterFactor);
end