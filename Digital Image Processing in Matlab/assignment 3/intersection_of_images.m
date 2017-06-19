function m = intersection_of_images(first, second)

[row1, column1] = size(first);
[row2, column2] = size(second);

maxRows = max(row1, row2);
maxColumns = max(column1, column2);

for r = 1:maxRows
    for c = 1:maxColumns
        if first(r,c) == second(r,c)
            m(r,c) = first(r,c);
        else
            m(r,c) = 0;
        end
    end
end

end