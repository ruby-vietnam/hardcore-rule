# @param {String} path
# @return {String}
def simplify_path(path)
  path_parts = path.split("/").select { |p| p != "" }
  path_components = []
  path_parts.each do |p|
    if p == "."
      next
    elsif p == ".."
      path_components.pop if path_components.length > 0
    else
      path_components << p
    end
  end
  "/" + path_components.join("/")
end
