class Triangle
{
    std::array<Vector3, 3> vertices_;
    GLuint buffer_id_;

public:
    Triangle()
    {
        vertices_[0] = Vector3(-0.5, 0.0, 0.0);
        vertices_[1] = Vector3(0.5, 0.0, 0.0);
        vertices_[2] = Vector3(0.0, 1.0, 0.0);

        // Create a new buffer and save the id.
        glGenBuffers(1, &buffer_id_);
        // Associate an actual buffer object with the id.
        glBindBuffer(GL_ARRAY_BUFFER, buffer_id_);

        draw();
    }

    void draw()
    {
        // Write vertex data into the buffer.
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_.data(), GL_DYNAMIC_DRAW);
    }

    void update(float x_pos, float y_pos)
    {
        vertices_[1] = Vector3(x_pos, y_pos, 0.0);
        draw();
    }
};