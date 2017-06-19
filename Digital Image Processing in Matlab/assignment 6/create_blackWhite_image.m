function m = create_blackWhite_image(row1, row2, column1, column2)

m = logical(zeros(255));

for r = row1 : row2
    for c = column1 : column2
        m(r,c) = 1;
    end
end
end