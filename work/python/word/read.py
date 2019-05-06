#code=utf-8

from docx import Document

#open doc
document = Document('stig_readme.docx')

#读取表格资料

for table in document.tables:
	for row in table.rows:
		for cell in row.cells:
			print(cell.text)
