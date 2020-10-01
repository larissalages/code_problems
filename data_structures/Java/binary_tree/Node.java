public class Node<T extends Comparable> {

    public Node left;
    public Node right;
    public T data;

    public Node(T data){
        this.left = null;
        this.right = null;
        this.data = data;
    }

    public void printTree(){
        if (left != null){
            left.printTree();
        }
        System.out.println(data);
        if (right != null){
            right.printTree();
        }
    }

    public void insert(T data){
        if (this.data != null){
            if (this.data.compareTo(data) < 0){
                if (this.left == null){
                    this.left = new Node<T>(data);
                    return;
                } else{
                    this.left.insert(data);
                }
            }
            else if (this.data.compareTo(data) > 0){
                if (this.right == null){
                    this.right = new Node<T>(data);
                    return;
                } else{
                    this.right.insert(data);
                }
            }
        }
        else{
            this.data = data;
        }
    }

    public void search_value(T data){
        if (this.data == data){
            System.out.println(String.format("Value %s is found", data));
        } else if (this.data.compareTo(data) < 0){
            this.left.search_value(data);
            return;
        } else if (this.data.compareTo(data) > 0){
            this.right.search_value(data);
            return;
        } else{
            System.out.println(String.format("Value %s does not exist!", data));
            return;
        }
    }
}
