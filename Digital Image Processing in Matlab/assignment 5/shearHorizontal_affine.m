function x = shearHorizontal_affine(sh, m)

[row, column] = size(m);
newColumn = round(sh * row + column);
x = zeros(row, newColumn);
aff = [1 sh 0; 0 1 0; 0 0 1];

for r = 1 : row
    for c = 1 : column
        a = aff * [r; c; 1];
        rowX = round(a(1,1));
        columnX = round(a(2,1));
        x(rowX, columnX) = m(r, c);
    end
end
x = logical(x(1:row, 1:column));
end