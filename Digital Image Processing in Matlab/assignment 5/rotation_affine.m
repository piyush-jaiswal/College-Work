function x = rotation_affine(angle, m)

[row, column] = size(m);
newRow = abs(round(row * cosd(angle) + column * sind(angle)));
newColumn = abs(round(column * cosd(angle) - row * sind(angle)));
x = zeros(newRow, newColumn);
aff = [cosd(angle) sind(angle) 1; -sind(angle) cosd(angle) 1; 0 0 1];

for r = 1 : row
    for c = 1 : column
        a = aff * [r; c; 1];
        rowX = round(a(1,1));
        columnX = round(a(2,1));
        if rowX < 0
            rowX = newRow + rowX;
        end
        if columnX < 0
            columnX = newColumn + columnX;
        end
        if rowX > 0 && rowX < newRow && columnX > 0 && columnX < newColumn
            x(rowX, columnX) = m(r, c);
        end
    end
end
end