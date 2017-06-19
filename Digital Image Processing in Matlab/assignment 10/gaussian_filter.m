function m = gaussian_filter(x)

[row, column] = size(x);
m = zeros(row, column);
filter = [1 2 1; 2 4 2; 1 2 1];

for i = 1:row
    m(i,1) = x(i,1);
    m(i, column) = x(i, column);
end

for i = 1:column
    m(1, i) = x(1, i);
    m(row, i) = x(row, i);
end

for r = 2 : row - 1
    for c = 2 : column - 1
        prod = x(r - 1: r + 1, c - 1: c + 1) .* uint8(filter);
        m(r,c) = round(sum(sum(prod)) / 9);
    end
end

m = uint8(m);
end
