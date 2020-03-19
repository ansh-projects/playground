using System;
using System.Collections.Generic;

namespace CSNodes
{
    class Node 
    {
        public static int getNumNodes()
        {
           return nodeNum;
        }
        public static int nodeNum = 0;
        public int Id {get; set; }
        public Node Parent { get; set; }
        public List<Node> Children { get; set; }

        public Node()
        {
            Id = ++nodeNum;
            Children = new List<Node>();
        }
        public Node(Node parent)
        {
            Id = ++nodeNum;
            Children = new List<Node>();
            Parent = parent;
            parent.Children.Add(this);
        }

        public override string ToString()
        {
            List<int> childIds = new List<int>();
            string parentId = "none";
            if(Parent != null)
            {
                parentId = Parent.Id.ToString();
            }
            string s = $@"
                Parent ID: {parentId}
                ID: {Id}
                Children: ";
            Children.ForEach(node => s += node.Id + " ");
            return s;
        }
    }

    class Program
    {
        static void AddKids(Node parent, int numKids)
        {
            if(numKids == 0)
            {
                return;
            }
            for(int i = 0; i < numKids; i++)
            {
                Node node = new Node(parent);
                AddKids(node, numKids - 1);
            }
        }

        static void StageNodeDeletion(Node parent, List<int> parentIds, List<int> childIds)
        {
            parentIds.Add(parent.Id);
            foreach(var child in parent.Children)
            {
                childIds.Add(child.Id);
                StageNodeDeletion(child, parentIds, childIds);
            }
        }

        static void StageNodeDeletionLeafs(Node parent, List<int> parentIds, List<int> childIds)
        {
            parentIds.Add(parent.Id);
            foreach(var child in parent.Children)
            {
                StageNodeDeletion(child, parentIds, childIds);
            }
        }

        static void Main(string[] args)
        {
            Node root = new Node();
            AddKids(root, 3);
            
            var parentIds = new List<int>();
            var childIds = new List<int>();
            StageNodeDeletion(root, parentIds, childIds);

            Console.WriteLine(Node.nodeNum);

        }
    }
}
