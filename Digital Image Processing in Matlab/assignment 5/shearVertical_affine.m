function x = shearVertical_affine(sv, m)

[row, column] = size(m);
newRow = round(row + column * sv);
x = zeros(newRow, column);
aff = [1 0 0; sv 1 0; 0 0 1];

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