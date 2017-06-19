function x = translate_affine(x0, y0, m)

[row, column] = size(m);
x = zeros(row + x0, column + y0);
aff = [1 0 x0; 0 1 y0; 0 0 1];

for r = 1 : row
    for c = 1 : column
        a = aff * [r; c; 1];
        rowX = a(1,1);
        columnX = a(2,1);
        x(rowX, columnX) = m(r, c);
    end
end
x = x(1:row, 1:column);
end


