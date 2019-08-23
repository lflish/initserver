#code=utf-8

import sys
from docx import Document
import json

def docx_2_text(docx_path):
	#open doc
	document = Document(docx_path)
	stig = {}

	for table in document.tables:
		d = {}

		name_key 	= 	table.rows[0].cells[0].text
		name_value 	= 	table.rows[0].cells[1].text
		d[name_key] 	= 	name_value

		vid_key 	= 	table.rows[1].cells[0].text
		vid_value	= 	table.rows[1].cells[1].text
		d[vid_key] 	= 	vid_value

		level_key 	= 	table.rows[1].cells[2].text
		level_value 	= 	table.rows[1].cells[3].text
		d[level_key] 	= 	level_value

		rule_key 	= 	table.rows[4].cells[0].text
		rule_value 	= 	table.rows[4].cells[1].text
		d[rule_key] 	= 	rule_value

		conf_key	= 	table.rows[5].cells[0].text
		conf_value 	= 	table.rows[5].cells[1].text
		d[conf_key] 	= 	conf_value

		stig[vid_value] = d

	return stig

def test(vid):
	stig_dict = docx_2_text('stig_readme.docx')
	print(stig_dict[vid])

stig_dict = docx_2_text('stig_readme.docx')

json = json.dumps(stig_dict, sort_keys = True, indent = 4, separators = (',', ':'), ensure_ascii = False)

print(json)
