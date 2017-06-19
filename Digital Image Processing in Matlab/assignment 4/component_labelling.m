%component labelling using N4 adjacency
function component_labelling(m)

m = logical(m);
[row, column] = size(m);
label = zeros(row, column);
count = 1;

for c = 1:column
    if m(1,c) == 1
        label(1,c) = count;
        count = count + 1;
    end
    if m(row,c) == 1
        label(row,c) = count;
        count = count + 1;
    end
end

for r = 1:row
    if m(r,1) == 1
        label(r,1) = count;
        count = count + 1;
    end
    if m(r,column) == 1
        label(r,column) = count;
        count = count + 1;
    end
end

for r = 2:row-1
    for c = 2:column-1
        if m(r,c) == 1
            % top = left = 0
            if(label(r-1,c) == 0 && label(r,c-1) == 0)
                label(r,c) = count;
                count = count + 1;
            % top = 0
            elseif label(r-1,c) == 0
                label(r,c) = label(r,c-1);
            % left = 0
            elseif label(r,c-1) == 0
                label(r,c) = label(r-1,c);
            % m(left) = m(top)
            else
                % top = left
                if label(r-1,c) == label(r,c-1)
                    label(r,c) = label(r-1,c);
                % top != left
                else
                    label(r,c) = label(r-1,c);
                    rc = find(label == label(r, c-1));
                    label(rc) = label(r-1, c);
                end
            end
        end
    end
end

label = intensity_range_adjustment(label);

for r = 1:row
    for c = 1:column
        if label(r,c) ~= 0
            label(r,c) = label(r,c) + 50;
        end
    end
end

imwrite(label, 'output.png');

                
                
            