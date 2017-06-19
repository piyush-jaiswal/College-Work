function [m, mX, mY] = sobel_filter(x)

filterSize = 3;
filterFactor = filterSize - 1;

[row, column] = size(x);
newRow = row + 2 * filterFactor;
newColumn = column + 2 * filterFactor;
m = zeros(newRow, newColumn);
filterX = [-1 -2 -1; 0 0 0; 1 2 1];
filterY = [-1 0 1; -2 0 2; -1 0 1];

%copy values from original matrix to m matrix
for r = 1 : row
    for c = 1 : column
        rowM = r + filterFactor;
        columnM = c + filterFactor;
        m(rowM, columnM) = x(r, c);
    end
end

% create initial x and y direction matrices
mX = zeros(newRow, newColumn);
mY = zeros(newRow, newColumn);

% compute the x and y direction matrices
for r = 2 : newRow - 1
    for c = 2 : newColumn - 1
        prodX = m(r - 1: r + 1, c - 1: c + 1) .* filterX;
        mX(r,c) = abs(sum(sum(prodX)));
        prodY = m(r - 1: r + 1, c - 1: c + 1) .* filterY;
        mY(r,c) = abs(sum(sum(prodY)));
    end
end

% compute the m matrix by x and y direction matrices
for r = 2 : newRow - 1
    for c = 2 : newColumn - 1
        m(r,c) = mX(r,c) + mY(r,c);
    end
end

m = uint8(m);
m = m(1 + filterFactor : newRow - filterFactor, 1 + filterFactor : newColumn - filterFactor);

mX = uint8(mX);
mX = mX(1 + filterFactor : newRow - filterFactor, 1 + filterFactor : newColumn - filterFactor);

mY = uint8(mY);
mY = mY(1 + filterFactor : newRow - filterFactor, 1 + filterFactor : newColumn - filterFactor);
end