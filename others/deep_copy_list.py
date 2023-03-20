def deep_copy_list(head):
	c = head
	new_head = None
	ap = {}

	# create new list
	while c:
		n = Node(c.value)
		ap[c] = n
		n.arbitrary = c.arbitrary # point to arbitrary of older list

		if not new_head:
			new_head = n
			pn = new_head

		else:
			pn.next = n
			pn = pn.next

		c = c.next

	# update arbitrary pointer in new list
	c = new_head
	while c:
		c.arbitrary = ap[a.arbitrary]
		c = c.next

	return new_head




