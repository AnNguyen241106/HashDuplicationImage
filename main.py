import hash_table_py as HashTable

ht = HashTable.HashTable(10, 10, 3)

vec1 = [1000, 2000, 3000]
vec2 = [-400, -500, -600]
vec3 = [100, -700, 900]
vec4 = [1001, 2000, 3000]
vec5 = [-401, -500, -600]

ht.addItem(vec1)
ht.addItem(vec2)
ht.addItem(vec3)
ht.addItem(vec4)
ht.addItem(vec5)


results = ht.search(vec5)
print(f"Tìm thấy {len(results)} vector(s) tương tự.")


ht.print()
